#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

typedef struct p
{
  int cents;
  struct p * next;
}PENNY;

typedef struct n
{
  int cents;
  struct n* nickel;
  PENNY* penny;
}NICKEL;

typedef struct d
{
  int cents;
  struct d* dime;
  NICKEL* nickel;
}DIME;

typedef struct q
{
  int cents;
  struct q* quarter;
  DIME* dime;
}QUARTER;

typedef struct t
{
  struct t* half;
  QUARTER* quarter;
  int cents;
}TREE;


int main()
{
    string line;
    while(getline(cin,line))
  	{
  		stringstream ss(line);
      int change;
      ss >> change;
      TREE* root = (TREE*) calloc (1,sizeof(TREE));
      root->cents = change;
      root = build_tree(root);

    }
}
