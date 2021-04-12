#include <iostream>
#include <string>
#define N 5

using namespace std;

class RealNumber;
void Swap(RealNumber& a, RealNumber& b);
void Obmin_Sort(RealNumber* arr);

class RealNumber
{
private:
    double value;

public:
    RealNumber() { value = 0; }
    RealNumber(double numb) { value = numb; }
    ~RealNumber() {};

    bool operator < (RealNumber& obj)
    {
        return this->IntPart() < obj.IntPart();
    }

    void operator [](double value)
    {
        double a = IntPart();
        this->value = this->CreateNum(this->IntPart(), value);
    }

    friend ostream& operator << (ostream& out, const RealNumber& numb);
    friend istream& operator >> (istream& in, RealNumber& numb);

    void SetValue(double value)
    {
        this->value = value;
    }

    double GetValue()
    {
        return value;
    }

    int IntPart()
    {
        int numb = value;
        return numb;
    }

    double DecPart()
    {
        return value - IntPart();
    }

    double CreateNum(int a, int b, int c = 0)
    {
        double dec_part = b;
        if (c == 0)
        {
            while (b > 0)
            {
                b /= 10;
                c++;
            }
        }


        for (int i = 0; i < c; i++)
        {
            dec_part /= 10;
        }
        return a + dec_part;
    }
};


int main()
{
    RealNumber arr[N];
    arr[0].SetValue(11.245);
    arr[1].SetValue(1);
    arr[2].SetValue(7.254);

    cout << arr[0];
    cout << arr[1];
    arr[1][68];
    cout << arr[1];

    cout << "enter the value of arr[3]" << endl;
    cin >> arr[3];
    cout << "enter the value of arr[4]" << endl;
    cin >> arr[4];

    Obmin_Sort(arr);
    cout << "\nSorted array:" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "\t" << arr[i];
    }
}

ostream& operator<<(ostream& out, const RealNumber& numb)
{
    out << "Real Number: " << numb.value << endl;
    return out;
}

istream& operator>>(istream& in, RealNumber& val)
{
    in >> val.value;
    return in;
}

void Obmin_Sort(RealNumber* arr)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (arr[j] < arr[i])
            {
                Swap(arr[j], arr[i]);
            }
        }
    }
}

void Swap(RealNumber& a, RealNumber& b)
{
    RealNumber temp = a;
    a = b;
    b = temp;
}