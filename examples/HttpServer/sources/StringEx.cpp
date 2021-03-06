#include "StringEx.h"
#include <memory.h>
#include <string.h>

int strsubstringpos(const char* str,const char* substr)
{
    char* pdest = (char*)strstr( str, substr );
    if(pdest == 0)
    {
        return -1;
    }
    int result = pdest - str;
    return result;
}

void strsplit(const string &str, vector<string> &tokens, const string &delimiters, bool trim)
{
    // Skip delimiters at beginning
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);

    // Find first non-delimiter
    string::size_type pos = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
		std::string item = str.substr(lastPos, pos - lastPos);

		if (trim)
		{
			stralltrim(item);
		}

		// Found a token, add it to the vector
		tokens.push_back(item);

        // Skip delimiters
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next non-delimiter
        pos = str.find_first_of(delimiters, lastPos);
    }
}

void strsplit(const string &str, vector<string> &tokens, char delim, bool trim)
{
    stringstream ss(str); //convert string to stream
    string item;

    while(getline(ss, item, delim))
    {
		if (trim)
		{
			stralltrim(item);
		}

        tokens.push_back(item); //add token to vector
    }
}

void strsplit(const string &str, list<string> &tokens, const string &delimiters, bool trim)
{
    // Skip delimiters at beginning
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);

    // Find first non-delimiter
    string::size_type pos = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
		std::string item = str.substr(lastPos, pos - lastPos);

		if (trim)
		{
			stralltrim(item);
		}

        // Found a token, add it to the vector
        tokens.push_back(item);

        // Skip delimiters
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next non-delimiter
        pos = str.find_first_of(delimiters, lastPos);
    }
}

void strsplit(const string &str, list<string> &tokens, char delim, bool trim)
{
    stringstream ss(str); //convert string to stream
    string item;

    while(getline(ss, item, delim))
    {
		if (trim)
		{
			stralltrim(item);
		}

        tokens.push_back(item); //add token to vector
    }
}


void strsplit(const string &str, char delim, string &keystr, string &valuestr, bool trim)
{
    stringstream ss(str); //convert string to stream
    string item;

    int ctr = 0;

    while(getline(ss, item, delim))
    {
        if(ctr==0)
        {
            keystr = item;
            ctr++;
            continue;
        }

        if(ctr==1)
        {
            valuestr = item;
            ctr++;
            continue;
        }

        if(ctr>1)
        {
            valuestr += delim;
            valuestr += item;
            ctr++;
        }
    }
}

int strsplit(const string &str, const string &delim, string &keystr, string &valuestr, bool trim)
{
    int pos = str.find(delim);

    if(pos == -1)
    {
        return pos;
    }

    char *tptr = new char[(size_t)pos+1];
    memset(tptr,0, (size_t)pos+1);

    memcpy(tptr, str.c_str(), pos);

    keystr = tptr;

    delete [] tptr;

    tptr = NULL;

    const char *ptr = str.c_str();

    valuestr = &ptr[pos+delim.length()];

    return pos;
}

void strreplace(string &srcstr, const char oldchar, const char newchar)
{
    int len = srcstr.length();
    for(int ctr = 0 ; ctr < len ; ctr++)
    {
        if(srcstr[ctr] == oldchar)
        {
            srcstr[ctr] = newchar;
        }
    }
}


void  strreplace(string &srcstr, const string oldpattern, const string newpattern)
{
    if (oldpattern.length() == 0 || srcstr.length() == 0)
    {
        return;
    }

    size_t idx = 0;

    for(;;)
    {
        idx = srcstr.find( oldpattern, idx);

        if (idx == string::npos)
        {
            break;
        }

        srcstr.replace( idx, oldpattern.length(), newpattern);
        idx += newpattern.length();
    }
}

void strreplace(string &srcstr, const string oldpattern, const char newchar)
{
	char buff[2]={0};
	buff[0] = newchar;
	strreplace(srcstr, oldpattern, buff);
}

void stralltrim(std::string &str)
{
    char buffer[4096];
    memset((char*)&buffer,0,4096);
    strcpy(buffer,str.c_str());

    int len = strlen(buffer);

    if(len<1)
        return;

    for(int i = len-1;  ; i--)
    {
        if(!isspace(buffer[i]) || i < 0)
        {
            break;
        }
        buffer[i] = '\0';
    }

    len = strlen(buffer);

    if(len<1)
    {
        str = buffer;
        return;
    }

    const char *buf=(const char*)&buffer[0];

    for ( NULL; *buf && isspace(*buf); buf++);

    str = buf;
}


bool charisspace(int in)
{
   if ((in == 0x20) || (in >= 0x09 && in <= 0x0D)) return true;
   return false;
}

int strcharcount(const char *str, char ch)
{
    int c=0;
    for(int i=0; str[i] != '\0' ;i++)
        if(str[i]==ch)
            c++;

    return c;
}

int	strcharacterpos(const char* str,const char ch)
{
    for(int ctr = 0; str[ctr] != '\0'; ctr++)
    {
        if(str[ctr]==ch)
        {
            return ctr;
        }
    }
    return -1;
}

void strrealtostring(string &str, const double val)
{
    char ptr[255];
    memset((void*)&ptr[0],0,255);
    sprintf(ptr,"%10.6lf",val);
    str = ptr;
}
