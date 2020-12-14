#include <iostream>
#include <vector>
using namespace std;
vector<vector<char>> box = {{'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                            {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                            {'+', '-', '-', '-', '-', '-', '-', '-', '+', '+'},
                            {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                            {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                            {'+', '-', '-', '-', '-', '-', '-', '+', '+', '+'},
                            {'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},
                            {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
                            {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
                            {'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'}};

void print()
{
    for (char i = 0; i < box.size(); i++)
    {
        for (char j = 0; j < box[0].size(); j++)
        {
            cout << box[i][j] << " ";
        }
        cout << "\n";
    }
}
bool canPH(string word, int i, int j)
{
    if ((j - 1 >= 0 && box[i][j - 1] != '+') || (j + word.size() <= box[0].size() && box[i][j + word.size()] != '+') || j + word.size() > box[0].size())
        return false;
    for (int jj = 0; jj < word.size(); jj++)
    {
        if (box[i][jj + j] != '-' && box[i][jj + j] != word[jj])
            return false;
    }
    return true;
}
bool canPV(string word, int i, int j)
{
    // cout<<word<<" ";
    if ((i - 1 >= 0 && box[i - 1][j] != '+') || i + word.size() > box.size() || (i + word.size() <= box.size() && box[i + word.size()][j] != '+'))
        return false;
    for (int ii = 0; ii < word.size(); ii++)
    {
        // cout << i << j << " ";
        if (box[i + ii][j] != '-' && box[i + ii][j] != word[ii])
        {
            return false;
        }
    }
    return true;
}
vector<bool> placeH(string word, int i, int j)
{
    // cout<<word<<" ";
    vector<bool> vis(word.size(), false);
    for (int jj = 0; jj < word.size(); jj++)
    {
        if (box[i][j+jj] == '-')
        {
            vis[jj] = true;
            box[i][j + jj] = word[jj];
        }
    }
    // print();
    return vis;
}
vector<bool> placeV(string word, int i, int j)
{
    vector<bool> vis(word.size(), false);
    for (int ii = 0; ii < word.size(); ii++)
    {
        if (box[i+ii][j] == '-')
        {
            vis[ii] = true;
            box[i+ii][j] = word[ii];
        }
    }
    // print();
    return vis;
}
void unplaceH(vector<bool> vis, int i, int j)
{
    for (int jj = 0; jj < vis.size(); jj++)
        if (vis[jj])
            box[i][j + jj] = '-';
}
void unplaceV(vector<bool> vis, int i, int j)
{
    for (int ii = 0; ii < vis.size(); ii++)
        if (vis[ii])
            box[i + ii][j] = '-';
}

void crossword(vector<string> words, int idx)
{
    // cout << idx;

    if (idx == words.size())
    {
        // cout<<"pp";
        print();
        return;
    }
    string word = words[idx];
    for (int i = 0; i < box.size(); i++)
    {
        for (int j = 0; j < box[0].size(); j++)
        {
            if (box[i][j] == '-' || box[i][j] == word[0])
            {
                if (canPH(word, i, j))
                {
                    // cout << "pp";
                    vector<bool> visH = placeH(word, i, j);
                    crossword(words, idx + 1);
                    unplaceH(visH, i, j);
                }
                if (canPV(word, i, j))
                {
                    // cout << "pp";
                    vector<bool> visV = placeV(word, i, j);
                    crossword(words, idx + 1);
                    unplaceV(visV, i, j);
                }
            }
        }
    }
}

void crossword()
{
    vector<string> words = {"agra", "norway", "england", "gwalior"};
    crossword(words, 0);
}
int main()
{
    crossword();
}
