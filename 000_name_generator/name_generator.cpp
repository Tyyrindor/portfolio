// need to fix the else is each function that has them
// they aren't updating the loop variable, need to recode them to something that works. look at old school work or search it

#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

string fnames[] = {"Alice", "Bob", "Mary"};
string lnames[] = {"Foo", "Bar", "Baz"};

bool yesno(string string)
{
  bool loop;
  bool result;
  transform(string.begin(), string.end(), string.begin(), ::toupper);
  do
  {
    if (string == "Y" | string == "YES")
    {
      result = true;
      loop = false;
      break;
    }
    else if (string == "N" | string == "NO")
    {
      result = false;
      loop = false;
      break;
    }
    else
    {
      cout << "Invalid entry.\n";
      loop = true;
      break;
    }
  } while (loop == true);

  return result;
}

int selection()
{
  int number;
  int confirm = 0;
  while(confirm == 0)
  {
    cout << "How many names do you want to generate? (Max 20): ";
    cin >> number;
    if(number < 1)
    {
      cout << "Invalid entry. Try again.\n";
      confirm = 0;
    }
    else if(number > 20)
    {
      cout << "Invalid entry. Try again.\n";
      confirm = 0;
    }
    else
    {
      confirm = 1;
      return number;
    }
  }
  return 0;
}

void generator(int number)
{
  while(number>0)
  {
    int x = rand() % 3;
    int y = rand() % 3;
    cout << fnames[x] << " " << lnames[y] << "\n";
    number--;
  }
}

int main()
{
  bool loop;
  string check;
  srand(time(0));

  do
  {
    int number = selection();

    generator(number);
    cout << "Generate more? (Y/N): ";
    cin >> check;
    loop = yesno(check);
  } while(loop == true);

  cout << "Terminating...\n";
  return 0;
}
