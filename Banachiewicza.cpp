#include <iostream>

using namespace std;

int main()
{
    const int n = 5;
    const int m = 5;
    
    double long a[m][n] = { 0.5,-3,4,-3,2,3,-5,0.5,0.5,4,-2,0.5,-4,-3,0.5,0.5,0.5,0.5,0.5,0.5,-2,-4,0.5,0.5,0.5 };
    double long b[m] = { 0.5,-2,0.5,-4,0.5 };
    
    double long l[m][n];
    double long u[m][n];
    double long y[n];
    double long x[n];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            l[i][j] = 0;
            u[i][j] = 0;
        }
        x[i] = 1;
        y[i] = 1;
    }

    for (int i = 0; i < n; i++)
        u[i][i] = 1;

    for (int i = 0; i < n; i++)
        l[i][0] = a[i][0];

    for (int j = 1; j < n; j++)
    {
        u[0][j] = a[0][j] / l[0][0];
    }

    for (int i = 1; i < n; i++)
        l[i][1] = a[i][1] - (l[i][0] * u[0][1]);

    double suma = 0;

    for (int j = 2; j < n; j++)
    {

        for (int i = 1; i < j; i++)
        {
            for (int s = 0; s < i; s++)
            {
                suma = suma + (l[i][s] * u[s][j]);
            }
            u[i][j] = (a[i][j] - suma) / l[i][i];
            suma = 0;
        }
        for (int i = j; i < n; i++)
        {
            for (int s = 0; s < j; s++)
            {
                suma = suma + (l[i][s] * u[s][j]);
            }
            l[i][j] = (a[i][j] - suma);
            suma = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << l[i][j] << "\t";

        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << u[i][j] << "\t";

        cout << endl;
    }
    y[1] = b[1] / l[1][1];
    for (int i = 1; i < n; i++)
    {
        for (int s = 0; s < i; s++)
        {
            suma = suma + (l[i][s] * y[s]);
        }
        y[i] = (b[i] - suma) / l[i][i];
        suma = 0;

    }
    x[n - 1] = y[n - 1] / u[n - 1][n - 1];
    for (int i = n - 2; i > -1; i--)

    {
        for (int s = i + 1; s < n; s++)
        {
            suma = suma + (u[i][s] * x[s]);
        }
        x[i] = (y[i] - suma) / u[i][i];
        suma = 0;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << ": " << x[i] << "\t";
    }
    
    cout << endl;
    
    return 0;
}