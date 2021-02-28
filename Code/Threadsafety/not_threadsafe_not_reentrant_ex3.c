char *strtoupper(char *string)
{
    static char buffer[MAX_STRING_SIZE];
    int index;

    for (index = 0; string[index]; index++)
            buffer[index] = toupper(string[index]);
    buffer[index] = 0

    return buffer;
}