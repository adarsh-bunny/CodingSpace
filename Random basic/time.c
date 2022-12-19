#include<stdio.h>
#include<string.h>

int main()
{
    int logcount=4;
    char * time="13:00:00"
    char **logdata;
    logdata= new char*[4];
    logdata[0]={'a','09:12:33','09:12:33'};
    logdata[1]={'b','10:34:04','15:45:09'};
    logdata[2]={'c','11:02:00','11:20:01'};
    logdata[2]={'d','11:47:06','12:01:00'};
    cout<< logdata[0]<<endl<< logdata[1]<<endl<< logdata[2]<<endl;
}