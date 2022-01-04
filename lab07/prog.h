typedef struct
{
    int total_chars;
    int letters_count;
    int words_count;
    int lines_count;
    int max_line_length;
} FileStats;

int is_letter(char);

FileStats *process_file(char *);

char **get_lines(char *);

void write_rev(char *, char **, int);