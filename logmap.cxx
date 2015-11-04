#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	double x0 = 0.5;  //Startwert
	double x;
	int Nskip = 0;  //Iterationsanzahl ohne Speicherung
	int Nend  = 100;  //Iterationsanzahl insgesamt
	int size=Nend-Nskip;  //Arraylänge für Datenspeicherung
	double xn[size];  //Array zurZwischenspeicherung
	
	fstream out("Daten.txt",ios::out);	
	fstream outplot("Daten_plot.txt",ios::out);

	for(double r=0; r <= 4; r += 0.001)
	{
	   x=x0;
	   for(int i=1; i <= Nskip; i++)
		   x = r*x*(1-x);
	   for(int i=0; i+Nskip < Nend; i++)
	   {
	   		   x = r*x*(1-x);
	   		   xn[i]=x;   
   	   }
	   for(int i=0;i<size;i++)
	   {
	   		out<<r<<"\t"<<xn[i]<<endl;
	   }	   
	}
	out.close();	
	
	//Plotbefehle in externer Datei speichern
	outplot<<"set terminal jpeg"<<endl;
	outplot<<"set output \"Plot.jpeg\" "<<endl;
	outplot<<"plot \"Daten.txt\" u 1:2 w dots"<<endl;
	outplot.close();
	
	//Gnuplot aufrufen und ausführen
	system("gnuplot  \"Daten_plot.txt\" ");
	return 0;
}
