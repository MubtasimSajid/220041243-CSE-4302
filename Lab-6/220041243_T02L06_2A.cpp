#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define result cout << answer << endl
#define all(entity) entity.begin(), entity.end()
#define full(entity) entity, entity + size
#define forRange(i, n) for (ll i = 0; i < n; i++)
using namespace std;

typedef long long ll;

class Matrix3D
{
    private:
        float a1, a2, a3, b1, b2, b3, c1, c2, c3, incrementValue;
        static int count;

    public:
        Matrix3D(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3)
        {
            this->a1 = a1;
            this->a2 = a2;
            this->a3 = a3;
            this->b1 = b1;
            this->b2 = b2;
            this->b3 = b3;
            this->c1 = c1;
            this->c2 = c2;
            this->c3 = c3;
            this->incrementValue = 1;
            count++;
        }
        ~Matrix3D()
        {
            count--;
        }
        double determinant() const
        {
            return a1 * (b2 * c3 - b3 * c2) - a2 * (b1 * c3 - b3 * c1) + a3 * (b1 * c2 - b2 * c1);
        }
        Matrix3D inverse() const
        {
            double det = determinant();
            if (!det)
                throw runtime_error("The matrix is singular (determinant is zero).");
            double invDet = 1.0 / det;

            Matrix3D coFactorMatrix(
                (b2 * c3 - b3 * c2), -(a2 * c3 - a3 * c2), (a2 * b3 - a3 * b2),
                -(b1 * c3 - b3 * c1), (a1 * c3 - a3 * c1), -(a1 * b3 - a3 * b1),
                (b1 * c2 - b2 * c1), -(a1 * c2 - a2 * c1), (a1 * b2 - a2 * b1));

            Matrix3D adjugateMatrix(
                coFactorMatrix.a1, coFactorMatrix.b1, coFactorMatrix.c1,
                coFactorMatrix.a2, coFactorMatrix.b2, coFactorMatrix.c2,
                coFactorMatrix.a3, coFactorMatrix.b3, coFactorMatrix.c3);

            Matrix3D inverseMatrix(
                adjugateMatrix.a1 * invDet, adjugateMatrix.a2 * invDet, adjugateMatrix.a3 * invDet,
                adjugateMatrix.b1 * invDet, adjugateMatrix.b2 * invDet, adjugateMatrix.b3 * invDet,
                adjugateMatrix.c1 * invDet, adjugateMatrix.c2 * invDet, adjugateMatrix.c3 * invDet);

            if (inverseMatrix.a1 == -0)
                inverseMatrix.a1 = 0;
            if (inverseMatrix.a2 == -0)
                inverseMatrix.a2 = 0;
            if (inverseMatrix.a3 == -0)
                inverseMatrix.a3 = 0;
            if (inverseMatrix.b1 == -0)
                inverseMatrix.b1 = 0;
            if (inverseMatrix.b2 == -0)
                inverseMatrix.b2 = 0;
            if (inverseMatrix.b3 == -0)
                inverseMatrix.b3 = 0;
            if (inverseMatrix.c1 == -0)
                inverseMatrix.c1 = 0;
            if (inverseMatrix.c2 == -0)
                inverseMatrix.c2 = 0;
            if (inverseMatrix.c3 == -0)
                inverseMatrix.c3 = 0;

            return inverseMatrix;
        }
        void setIncrement(int value)
        {
            if (!count && value >= 0)
                incrementValue = value;
            else
                cout << "Increment step cannot be set." << endl;
            return;
        }
        Matrix3D getMatrix() const
        {
            cout << a1 << " " << a2 << " " << a3 << endl;
            cout << b1 << " " << b2 << " " << b3 << endl;
            cout << c1 << " " << c2 << " " << c3 << endl;
            cout << endl;
            return *this;
        }
        void increment()
        {
            a1 += incrementValue;
            a2 += incrementValue;
            a3 += incrementValue;
            b1 += incrementValue;
            b2 += incrementValue;
            b3 += incrementValue;
            c1 += incrementValue;
            c2 += incrementValue;
            c3 += incrementValue;

            return;
        }
        bool operator>(Matrix3D const &m)
        {
            return determinant() > m.determinant();
        }
        bool operator<(Matrix3D const &m)
        {
            return determinant() < m.determinant();
        }
        bool operator>=(Matrix3D const &m)
        {
            return determinant() >= m.determinant();
        }
        bool operator<=(Matrix3D const &m)
        {
            return determinant() <= m.determinant();
        }
        bool operator==(Matrix3D const &m)
        {
            return determinant() == m.determinant();
        }
        bool operator!=(Matrix3D const &m)
        {
            return determinant()!= m.determinant();
        }
        Matrix3D operator+(const Matrix3D &m) const
        {
            return Matrix3D(
                a1 + m.a1, a2 + m.a2, a3 + m.a3,
                b1 + m.b1, b2 + m.b2, b3 + m.b3,
                c1 + m.c1, c2 + m.c2, c3 + m.c3);
        }
        Matrix3D operator-(const Matrix3D &m) const
        {
            return Matrix3D(
                a1 - m.a1, a2 - m.a2, a3 - m.a3,
                b1 - m.b1, b2 - m.b2, b3 - m.b3,
                c1 - m.c1, c2 - m.c2, c3 - m.c3);
        }
        Matrix3D operator*(const Matrix3D &m) const
        {
            return Matrix3D(
                a1 * m.a1 + a2 * m.b1 + a3 * m.c1,
                a1 * m.a2 + a2 * m.b2 + a3 * m.c2,
                a1 * m.a3 + a2 * m.b3 + a3 * m.c3,

                b1 * m.a1 + b2 * m.b1 + b3 * m.c1,
                b1 * m.a2 + b2 * m.b2 + b3 * m.c2,
                b1 * m.a3 + b2 * m.b3 + b3 * m.c3,

                c1 * m.a1 + c2 * m.b1 + c3 * m.c1,
                c1 * m.a2 + c2 * m.b2 + c3 * m.c2,
                c1 * m.a3 + c2 * m.b3 + c3 * m.c3);
        }
};

int Matrix3D::count = 0;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Matrix3D m1(1, 0, 0, 0, 1, 0, 0, 0, 1);
    m1.getMatrix();
    cout << m1.determinant() << endl;

    Matrix3D m2 = m1.inverse();
    m2.getMatrix();

    return 0;
}