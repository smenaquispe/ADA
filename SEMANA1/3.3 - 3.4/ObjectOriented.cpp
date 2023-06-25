#include<iostream>
using namespace std;

template<typename Type>
class CVector {
    private:
        Type * m_pVect;
        int m_nCount = 0,
            m_nMax = 0,
            m_nDelta;
        void Init(int delta);
        void Resize();
    public:
        CVector(int delta = 10);
        void Insert(Type elem);
        void Print();
};

template<typename Type>
void CVector<Type>::Init(int delta) {
    this->m_nDelta = delta;
    m_pVect = new Type[delta];
}

template<typename Type>
void CVector<Type>::Resize() {
    
    Type *pTemp;
    pTemp = new Type[m_nMax + m_nDelta];
    for(int i = 0; i < m_nMax; i++)
        pTemp[i] = m_pVect[i];

    delete [] m_pVect;
    m_pVect = pTemp;

    m_nMax += m_nDelta;
}

template<typename Type>
CVector<Type>::CVector(int delta) {
    Init(delta);
}

template<typename Type>
void CVector<Type>::Insert(Type elem) {
    if(m_nCount == m_nMax) 
        Resize();
    m_pVect[m_nCount++] = elem;
}

template<typename Type>
void CVector<Type>::Print() {
    for(int i = 0; i < m_nCount; i++)
        cout<<m_pVect[i]<<" ";
    cout<<endl;
}

int main() {

    CVector<float> vect(10);
    vect.Insert(5);
    vect.Insert(3);
    vect.Insert(4.333);
    vect.Insert(6.123);
    vect.Print();
    return 0;
}