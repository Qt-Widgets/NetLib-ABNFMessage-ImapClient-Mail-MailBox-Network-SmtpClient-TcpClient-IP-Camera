#include "StringExC.h"

wchar_t *strtowstr(const char *str)
{
    return NULL;
}

char* strfromwstr(wchar_t* wstr)
{
    size_t wlen = 0;
    char* str = NULL;

    if (wstr != NULL)
    {
        for (wlen = 0; wstr[wlen] != '\0'; wlen++) {}

        str = (char*)malloc(wlen+1);
        memset(str, 0, wlen+1);

        for (size_t idx = 0; idx < wlen; idx++)
        {
            str[idx] = wstr[idx];
        }
    }

    return str;
}

char* strfromint(size_t num)
{
	char* ptr = (char*)malloc((size_t)32);
	memset(ptr, 0, (size_t)32);

	int sign = 1;
	size_t remainder = 1;
	size_t dividend = num;
	size_t ctr = 0;

	if (num < 1)
	{
		sign = -1;
		dividend = dividend*-1;
	}

	while (dividend)
	{
		remainder = dividend % 10;
		dividend = dividend / 10;

		ptr[ctr] = remainder + 48;
		ctr++;
	}

	if (sign < 1)
	{
		ptr[ctr] = '-';
	}
	else
	{
		ctr--;
	}

	size_t start = 0;

	while (start < ctr)
	{
		char temp = ptr[start];
		ptr[start] = ptr[ctr];
		ptr[ctr] = temp;
		start++;
		ctr--;
	}

	return ptr;
}

char* strfromdouble(double num)
{
	return NULL;
}

#if !defined(_WIN32) && !defined(WIN32) && !defined (_WIN64) && !defined (WIN64)

char* strrev(char* ptr)
{
	size_t start = 0;

	size_t term = strlen(ptr) - 1;

	while (start < term)
	{
		char temp = ptr[start];
		ptr[start] = ptr[term];
		ptr[term] = temp;
		start++;
		term--;
	}

	return ptr;
}

#endif

char* strsegrev(char* str, size_t start, size_t term)
{
	while (start < term)
	{
        char temp = str[start];
        str[start] = str[term];
        str[term] = temp;
		start++;
		term--;
	}

    return str;
}

int strindexofsubstr(char* str, const char* substr)
{
    return -1;
}

int strindexofchar(char* str, const char ch)
{
    for (int ctr = 0; str[ctr] != '\0'; ctr++)
    {
        if (str[ctr] == ch)
        {
            return ctr;
        }
    }

    return -1;
}

extern char* strtolower(char* str)
{
    for (size_t ctr = 0; str[ctr] != '\0'; ctr++)
    {
        if (str[ctr] >= 65 && str[ctr] <= 90)
        {
            str[ctr] = str[ctr] + 32;
        }
    }

    return str;
}

extern char* strtoupper(char* str)
{
    for (size_t ctr = 0; str[ctr] != '\0'; ctr++)
    {
        if (str[ctr] >= 97 && str[ctr] <= 122)
        {
            str[ctr] = str[ctr] - 32;
        }
    }

    return str;
}

char* strlefttrim(char* str)
{
    char *ptr = str;

    int ctr = 0;

    int trimlen = 0;

    while (isspace(*ptr))
    {
        ptr++;
        trimlen++;
    }

    while (*ptr)
    {
        str[ctr] = *ptr;
        ctr++;
        ptr++;
    }

    str[ctr] = '\0';

    return str;
}

char* strrighttrim(char* str)
{
    size_t len = strlen(str);

    for (size_t ctr = len - 1; ctr > -1; ctr--)
    {
        if (isspace(str[ctr]))
        {
            str[ctr] = '\0';
        }
        else
        {
            break;
        }
    }

    return str;
}

char* stralltrim(char* str)
{
    strrighttrim(str);
    strlefttrim(str);

    return str;
}

char* strremsubstrfirst(char* str, const char* substr)
{
    return NULL;
}

char* strremsubstrall(char* str, const char* substr)
{
    return NULL;
}

char* strremsubstrat(char* str, size_t pos, size_t len)
{
    return NULL;
}


char* strremcharfirst(char* str, const char oldchar)
{
    return NULL;
}

char* strremcharall(char* str, const char oldchar)
{
    return NULL;
}

char* strremcharat(char* str, size_t pos)
{
    return NULL;
}

char* strrepsubstrfirst(char* str, const char* substr)
{
    return NULL;
}

char* strrepsubstrall(char* str, const char* substr)
{
    return NULL;
}

char* strrepsubstrat(char* str, size_t pos, size_t len)
{
    return NULL;
}

char* strrepcharfirst(char* str, const char oldchar)
{
    return NULL;
}

char* strrepcharall(char* str, const char oldchar)
{
    return NULL;
}

char* strrepcharat(char* str, size_t pos)
{
    return NULL;
}
