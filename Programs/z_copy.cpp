// Copy Program

#include <iostream>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main()

{

    char sfile[30], tfile[30], buf[1000];

    int sd, td, n;

    cout << "Enter the source filename" << endl;

    cin >> sfile;

    cout << "Enter the target filename" << endl;

    cin >> tfile;

    if ((sd = open(sfile, O_RDONLY)) < 0)

    {

        cout << "Error Opening File" << endl;

        exit(1);
    }

    if ((td = open(tfile, O_CREAT | O_WRONLY, 0666)) < 0)

    {

        cout << "Error Creating File" << endl;

        close(sd);

        exit(2);
    }

    while ((n = read(sd, buf, sizeof(buf))) > 0)

        write(td, buf, n);

    close(sd);

    close(td);

    cout << "File Copied" << endl;

    return 0;
}
