   #include<stdio.h>
 #include<ctime>
 // system date ahd time
    using namespaced std;
    int main()
    {
        time_t nowuptime=time(0);
        char*date=ctime(&nowuotime);
        cout<<"current date and time is "<<"\n";
        cout<<date<<end1;
    }


