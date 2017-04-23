#include "CGL.h"
#include "Mat.h"

using namespace acLib::cgl;
using namespace acLib::mat;

int main()
{
    Mat33 mat(1.0, 2.0, 1.0,
        2.0, 1.0, 0.0,
        1.0, 1.0, 2.0);

    Mat33 invMat = mat.Inverse();

    cout << mat << endl;
    cout << invMat << endl;
    return 0;
}