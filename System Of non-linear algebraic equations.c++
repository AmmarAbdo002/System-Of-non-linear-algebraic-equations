#include<iostream>
#include<cmath>
using namespace std;
void Newtons();
int main()
{
    void Newtons(); 

    return 0;
}



void Newtons()
{
    double x1, x2;

    double p1_x1, p2_x1;
    double pow1_x1, pow2_x1;

    double p1_x2, p2_x2;
    double pow1_x2, pow2_x2;

    double num_f1;
    double num_f2;

    cout << "Enter Equation 1" << endl;
    cout << "x1 Parameter :";
    cin >> p1_x1;
    cout << "x1 power :";
    cin >> pow1_x1;
    cout << endl;

    cout << "x2 Parameter :";
    cin >> p1_x2;
    cout << "x2 power :";
    cin >> pow1_x2;
    cout << endl;

    cout << "integer number :";
    cin >> num_f1;
    cout << "\n____________________________________________________\n\n";

    cout << "Enter Equation 2" << endl;
    cout << "x1 Parameter :";
    cin >> p2_x1;
    cout << "x1 power :";
    cin >> pow2_x1;
    cout << endl;

    cout << "x2 Parameter :";
    cin >> p2_x2;
    cout << "x2 power :";
    cin >> pow2_x2;
    cout << endl;

    cout << "integer number :";
    cin >> num_f2;
    cout << "\n____________________________________________________\n\n";

    cout << "Enter the initial point" << endl;
    cout << "X1 :";
    cin >> x1;
    cout << "X2 :";
    cin >> x2;

    for (int i = 0; i < 2; i++)
    {
        double f1 = (p1_x1 * pow(x1, pow1_x1)) + (p1_x2 * pow(x2, pow1_x2)) + num_f1;
        double df1_x1 = p1_x1 * pow1_x1 * pow(x1, pow1_x1 - 1);
        double df1_x2 = p1_x2 * pow1_x2 * pow(x2, pow1_x2 - 1);

        double f2 = (p2_x1 * pow(x1, pow2_x1)) + (p2_x2 * pow(x2, pow2_x2)) + num_f2;
        double df2_x1 = p2_x1 * pow2_x1 * pow(x1, pow2_x1 - 1);
        double df2_x2 = p2_x2 * pow2_x2 * pow(x2, pow2_x2 - 1);

        double Invars_p = 1 / ((df1_x1 * df2_x2) - (df1_x2 * df2_x1));

        double Invars_df[2][2] =
            {
                {Invars_p * df2_x2, Invars_p * -df1_x2},
                {Invars_p * -df2_x1, Invars_p * df1_x1}};

        double matrix_x[2][1] =
            {
                {x1},
                {x2}};

        double matrix_f[2][1] =
            {
                {f1},
                {f2}};

        double multiply[2][1];

        for (int i = 0; i < 2; i++)
        {
            multiply[i][0] = 0;
            for (int j = 0; j < 2; j++)
            {
                multiply[i /*1*/][0] += Invars_df[i /*1*/][j /*0*/] * matrix_f[j /*0*/][0];
            }
        }
        double result[2][1];

        for (int i = 0; i < 2; i++)
        {
            result[i][0] = matrix_x[i][0] - multiply[i][0];
        }
        x1 = result[0][0];
        x2 = result[1][0];
    }

    cout << "\n___________________________________________________________\n\n";
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2;
}
