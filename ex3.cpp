/*#include <iostream>
#include <cassert>
using namespace std;
class Matrix
{
private:
int data[2][2];
public:
Matrix(int a = 0, int b = 0, int c = 0, int d = 0)
{
data[0][0] = a;
data[0][1] = b;
data[1][0] = c;


        data[1][1] = d;
    }
    // Operator +
    Matrix operator+(const Matrix &m)
    {
        Matrix result;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                result.data[i][j] = data[i][j] + m.data[i][j];
        return result;
    }
    // Operator *
    Matrix operator*(const Matrix &m)
    {
        Matrix result;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result.data[i][j] = 0;
                for (int k = 0; k < 2; k++)
                    result.data[i][j] += data[i][k] * m.data[k][j];
                 }
        }
        return result;
    }
    // Operator []
    int* operator[](int index)
    {
        return data[index];
    }

    // Operator <<
    friend ostream& operator<<(ostream &out, const Matrix &m)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
                out << m.data[i][j] << " ";
            out << endl;
        }
        return out;
    }
};
int main()
{
    Matrix A(1, 2, 3, 4);
    Matrix B(5, 6, 7, 8);
    Matrix sum = A + B;
    Matrix product = A * B;
    // Unit Tests
    assert(sum[0][0] == 6);
    assert(sum[1][1] == 12);
    assert(product[0][0] == 19);
    assert(product[0][1] == 22);
    assert(product[1][0] == 43);
    assert(product[1][1] == 50);
    cout << "Matrix A:" << endl;
    cout << A;
    cout << "Matrix B:" << endl;
    cout << B;
cout << "Addition of Matrices:" << endl;
cout << sum;
cout << "Multiplication of Matrices:" << endl;
cout << product;
cout << "All unit tests passed successfully." << endl;
return 0;
}*/


#include <iostream>
#include <cassert>
using namespace std;

class Matrix
{
private:
    int data[2][2];

public:
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0)
    {
        data[0][0] = a;
        data[0][1] = b;
        data[1][0] = c;
        data[1][1] = d;
    }

    // Operator +
    Matrix operator+(const Matrix &m)
    {
        Matrix result;

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                result.data[i][j] = data[i][j] + m.data[i][j];

        return result;
    }

    // Operator *
    Matrix operator*(const Matrix &m)
    {
        Matrix result;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result.data[i][j] = 0;

                for (int k = 0; k < 2; k++)
                    result.data[i][j] += data[i][k] * m.data[k][j];
            }
        }

        return result;
    }

    // Operator []
    int* operator[](int index)
    {
        return data[index];
    }

    // Operator <<
    friend ostream& operator<<(ostream &out, const Matrix &m)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
                out << m.data[i][j] << " ";

            out << endl;
        }

        return out;
    }
};

int main()
{
    int a, b, c, d;
    int e, f, g, h;

    cout << "Enter 4 elements of Matrix A:" << endl;
    cin >> a >> b >> c >> d;

    cout << "Enter 4 elements of Matrix B:" << endl;
    cin >> e >> f >> g >> h;

    Matrix A(a, b, c, d);
    Matrix B(e, f, g, h);

    Matrix sum = A + B;
    Matrix product = A * B;

    // Unit Tests
    assert(sum[0][0] == a + e);
    assert(sum[1][1] == d + h);

    assert(product[0][0] == a * e + b * g);
    assert(product[0][1] == a * f + b * h);
    assert(product[1][0] == c * e + d * g);
    assert(product[1][1] == c * f + d * h);

    cout << "\nMatrix A:" << endl;
    cout << A;

    cout << "Matrix B:" << endl;
    cout << B;

    cout << "Addition of Matrices:" << endl;
    cout << sum;

    cout << "Multiplication of Matrices:" << endl;
    cout << product;

    cout << "All unit tests passed successfully." << endl;

    return 0;
}   