#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Flight
{
    char flight_number[20];
    char departure_time[10];
    char arrival_time[10];
    char direction[50];
    char aircraft[20];
    float distance;
} Flight;

Flight* read_flight_data(const char* filename, int* num_flights)
{
    FILE* file;
    if (fopen_s(&file, filename, "r") != 0)
    {
        perror("Ошибка открытия файла");
        return NULL;
    }

    int count = 0;
    char buffer[100]; // Буфер для чтения строки из файла
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        count++;
    }

    rewind(file);

    Flight* flights = (Flight*)malloc(count * sizeof(Flight));
    if (flights == NULL)
    {
        perror("Mem error.");
        return NULL;
    }

    int i = 0;
    while (fscanf(file, "%19[^;];%9[^;];%9[^;];%49[^;];%19[^;];%f\n",
        flights[i].flight_number, flights[i].departure_time, flights[i].arrival_time,
        flights[i].direction, flights[i].aircraft, &flights[i].distance) != EOF)
    {
        i++;
    }

    *num_flights = count;
    fclose(file);
    return flights;
}

int time_to_minutes(const char* time)
{
    int hours, minutes;
    sscanf(time, "%d:%d", &hours, &minutes);
    return hours * 60 + minutes;
}

Flight find_longest_flight(Flight* flights, int num_flights)
{
    int max_duration = 0;
    Flight longest_flight;

    for (int i = 0; i < num_flights; ++i)
    {
        int departure_minutes = time_to_minutes(flights[i].departure_time);
        int arrival_minutes = time_to_minutes(flights[i].arrival_time);
        int duration = arrival_minutes - departure_minutes;

        if (duration > max_duration)
        {
            max_duration = duration;
            longest_flight = flights[i];
        }
    }

    return longest_flight;
}

void write_longest_flight(const char* filename, Flight longest_flight)
{
    FILE* file;
    if (fopen_s(&file, filename, "w") != 0)
    {
        perror("Ошибка открытия файла");
        return;
    }

    fprintf(file, "%s;%s;%s;%s;%s;%.2f",
        longest_flight.flight_number, longest_flight.departure_time, longest_flight.arrival_time,
        longest_flight.direction, longest_flight.aircraft, longest_flight.distance);

    fclose(file);
}

int main()
{
    int num_flights;
    const char* input_filename = "input.txt";
    const char* output_filename = "output.txt";

    Flight* flights = read_flight_data(input_filename, &num_flights);
    if (flights == NULL) {
        return EXIT_FAILURE;
    }

    Flight longest_flight = find_longest_flight(flights, num_flights);
    write_longest_flight(output_filename, longest_flight);

    free(flights);
    return EXIT_SUCCESS;
}