//////////////////////////////
//                          //
// Rueil Manzambi           //
// hpp file for arraylist.h //
//                          //
//////////////////////////////

#include <iostream>
using namespace std;

template <typename T>
void ArrayList<T>::grow(){
  T * tmp;
  tmp = new T[m_max*2];

  for (int i=0; i < m_size; i++)
    tmp[i] = m_data[i];
  delete [] m_data;
  m_data = tmp;
  m_max = m_max * 2;
}

template <typename T>
void ArrayList<T>::shrink(){
  T * tmp;
  tmp = new T[m_max/2];

  for (int i = 0; i < m_size; i++)
    tmp[i] = m_data[i];
  delete [] m_data;
  m_data = tmp;
  m_max = m_max / 2;
  return;
}

template <typename T>
ArrayList<T>::ArrayList(int s, const T& x){
  m_size = s;
  m_data = new T[s];
  for (int i = 0; i < m_size; i++)
    m_data[i] = x;
}

template <typename T>
ArrayList<T>::~ArrayList(){
  delete [] m_data;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs){
  if  (this != &rhs){
    delete [] m_data;
    m_size = rhs.m_size;
    m_max = rhs.m_max;
    m_data = new T[m_max];

    for (int i = 0; i < m_size; i++)
      m_data[i] = rhs.m_data[i];
  }
  return *this;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy){
  m_data = NULL;
  *this = cpy;
}

template <typename T>
int ArrayList<T>::size() const{
  return m_size;
}

template <typename T>
const T& ArrayList<T>:: first() const{
  if (m_size <= 0){
    cout <<"!-- ERROR : PANIC in ARRAYLIST!!.first()  (List is empty)" << endl;
    return m_errobj;
  }
  else
    return m_data[0];
}

template <typename T>
T& ArrayList<T>::operator [](int i){
  if (i >= m_size){
    cout <<"!-- ERROR : PANIC in ARRAYLIST!!.[]  (index out of bounds)" << endl;
    cout <<"-  ";
    return m_errobj;
  }
  else
    return m_data[i];
}

template <typename T>
const T& ArrayList<T>::operator[](int i) const{
  if (m_size <= 0){
    cout <<"!-- ERROR : PANIC in ARRAYLIST!!.[]  (index out of bounds)" << endl;
    cout << "-  ";
    return m_errobj;
  }
  else
    return m_data[i];
}

template <typename T>
int ArrayList<T>::search(const T& x) const{
  bool found = false;
  bool first = true;
  int position;

  for (int i = 0; i < m_size; i++){
    if  ((m_data[i] == x) && (first)){
      found = true;
      first = false;
      position = i;
    }
  }

  if (found)
    return position;
  else
    return -1;
}

template <typename T>
void ArrayList<T>::clear(){
  delete [] m_data;
  m_size = 0;
  m_max = 4;
  m_data = new T[m_max];

  return;
}

template <typename T>
void ArrayList<T>::insert_back(const T& x){
  if (m_size == m_max)
    grow();
  m_data[m_size] = x;
  m_size++;
  return;
}

template <typename T>
void ArrayList<T>::insert(const T& x, int i){
  if (!(i >= m_size)){
    if (m_size == m_max)
      grow();
    for (int j = m_size; j > i; j--)
      m_data[j] = m_data[j-1];
    m_data[i] = x;
    m_size++;
  }
  else
    cout  << "!-- ERROR : PANIC in ARRAYLIST!!.insert()  (index out of bounds)" <<endl;
  return;
}

template <typename T>
void ArrayList<T>::remove(int i){
  if (!(i >= m_size)){
    for (int j = i; j < m_size-1; j++)
      m_data[j] = m_data[j+1];
    if (m_size > 0)
      m_size--;
    if (m_size < (m_max/4))
      shrink();
  }
  else
    cout <<"!-- ERROR : PANIC in ARRAYLIST!!.remove()  (index out of bounds)"<< endl;
  return;
}

template <typename T>
void ArrayList<T>::swap(int i, int k){
  if ((i <= m_size)&&(k <= m_size)){
    T tmp;
    tmp = m_data[i];
    m_data[i] = m_data[k];
    m_data[k] = tmp;
  }
  else
    cout <<"!-- ERROR : PANIC in ARRAYLIST!!.swap()  (index out of bounds)"<<endl;
  return;
}

template <typename T>
void ArrayList<T>::purge(){

  for (int i = 0; i < m_size; i++){
    for (int j = i+1; j < m_size; j++){
      if (m_data[i] == m_data[j]){
        for (int k = j; k < m_size - 1; k++)
          m_data[k] = m_data[k+1];
        m_size--;
        j--;
      }
    }
  }
  return;
}

template <typename T>
void ArrayList<T>::reverse(){
  int pos = 0;
  T* tmp;
  tmp = new T[m_max];

  for (int i = m_size-1; i >= 0; i--){
    tmp[pos] = m_data[i];
    pos++;
  }
  delete [] m_data;
  m_data = tmp;
  return;
}
