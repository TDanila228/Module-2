
int main() {
    const char* inputFileName = "input.txt"; // �������� �������� �����
    const char* outputFileName = "output.txt"; // �������� ����� ��� ������ ����������

    replace_to_0(inputFileName, outputFileName); // �������� ������� ������ ��������

    printf("Replace success. Result in '%s'.\n", outputFileName); // ������� ��������� �� �������� ����������

    return 0;
}