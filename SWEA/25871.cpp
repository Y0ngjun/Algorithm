// 25871. [사전 문제] 타일 매칭
#include <cstring>

using namespace std;

#define WIDTH (8)

// (0, 0)이 보드의 좌하단
int board[8][8];
int mTilesFront[8];
int (*_mTiles)[8];
int mRet[5];

int calculateRowScore(int row)
{
    int score = 0;

    for (int x = 0; x + 2 < 8;)
    {
        int cnt = 1;

        for (int nx = x + 1; nx < 8; ++nx)
        {
            if (board[row][nx] != board[row][x])
            {
                break;
            }

            ++cnt;
        }

        if (cnt < 3)
        {

        }
        else if (cnt == 3)
        {
            score += 1;
        }
        else if (cnt == 4)
        {
            score += 4;
        }
        else
        {
            score += 9;
        }

        x += cnt;
    }

    return score;
}

int calculateColScore(int col)
{
    int score = 0;

    for (int y = 0; y + 2 < 8;)
    {
        int cnt = 1;

        for (int ny = y + 1; ny < 8; ++ny)
        {
            if (board[ny][col] != board[y][col])
            {
                break;
            }

            ++cnt;
        }

        if (cnt < 3)
        {

        }
        else if (cnt == 3)
        {
            score += 1;
        }
        else if (cnt == 4)
        {
            score += 4;
        }
        else
        {
            score += 9;
        }

        y += cnt;
    }

    return score;
}

inline void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void calculateMaxScore()
{
    mRet[0] = 0;

    for (int y = 0; y < 8; ++y)
    {
        for (int x = 0; x < 8; ++x)
        {
            if (x + 1 < 8 && board[y][x] != board[y][x + 1])
            {
                swap(board[y][x], board[y][x + 1]);
                int score = calculateRowScore(y) + calculateColScore(x) + calculateColScore(x + 1);
                swap(board[y][x], board[y][x + 1]);

                if (score > mRet[0])
                {
                    mRet[0] = score;
                    mRet[1] = y;
                    mRet[2] = x;
                    mRet[3] = y;
                    mRet[4] = x + 1;
                }
            }

            if (y + 1 < 8 && board[y][x] != board[y + 1][x])
            {
                swap(board[y][x], board[y + 1][x]);
                int score = calculateRowScore(y) + calculateRowScore(y + 1) + calculateColScore(x);
                swap(board[y][x], board[y + 1][x]);

                if (score > mRet[0])
                {
                    mRet[0] = score;
                    mRet[1] = y;
                    mRet[2] = x;
                    mRet[3] = y + 1;
                    mRet[4] = x;
                }
            }
        }
    }
}

void fillBoard()
{
    for (int x = 0; x < 8; ++x)
    {
        int idx = 0;

        for (int y = 0; y < 8; ++y)
        {
            if (board[y][x] > 0)
            {
                board[idx++][x] = board[y][x];
            }
        }

        while (idx < 8)
        {
            board[idx++][x] = _mTiles[mTilesFront[x]++][x];
        }
    }
}

void resetBoard()
{
    for (int y = 0; y < 8; ++y)
    {
        for (int x = 0; x < 8; ++x)
        {
            board[y][x] = _mTiles[mTilesFront[x]++][x];
        }
    }
}

int deleteTiles()
{
    int score = 0;
    bool marked[8][8] = {};

    // 가로체크
    for (int y = 0; y < 8; ++y)
    {
        for (int x = 0; x + 2 < 8;)
        {
            int cnt = 1;

            for (int nx = x + 1; nx < 8; ++nx)
            {
                if (board[y][nx] != board[y][x])
                {
                    break;
                }

                ++cnt;
            }

            if (cnt < 3)
            {

            }
            else if (cnt == 3)
            {
                score += 1;
            }
            else if (cnt == 4)
            {
                score += 4;
            }
            else
            {
                score += 9;
            }

            if (cnt >= 3)
            {
                for (int nx = x; nx < x + cnt; ++nx)
                {
                    marked[y][nx] = true;
                }
            }

            x += cnt;
        }
    }

    // 세로체크
    for (int x = 0; x < 8; ++x)
    {
        for (int y = 0; y + 2 < 8;)
        {
            int cnt = 1;

            for (int ny = y + 1; ny < 8; ++ny)
            {
                if (board[ny][x] != board[y][x])
                {
                    break;
                }

                ++cnt;
            }

            if (cnt < 3)
            {

            }
            else if (cnt == 3)
            {
                score += 1;
            }
            else if (cnt == 4)
            {
                score += 4;
            }
            else
            {
                score += 9;
            }

            if (cnt >= 3)
            {
                for (int ny = y; ny < y + cnt; ++ny)
                {
                    marked[ny][x] = true;
                }
            }

            y += cnt;
        }
    }

    for (int y = 0; y < 8; ++y)
    {
        for (int x = 0; x < 8; ++x)
        {
            if (marked[y][x])
            {
                board[y][x] = 0;
            }
        }
    }

    return score;
}

void init(int N, int mTiles[][WIDTH])
{
    _mTiles = mTiles;
    memset(mTilesFront, 0, sizeof(mTilesFront));
    resetBoard();
}

int* takeTurn()
{
    // 1. 격자를 준비 상태로 만든다.
    // 1-a. 격자 내 빈 공간이 없어야 한다.
    // 1-b. 같은 타일이 3개 이상 연속되는 경우가 없어야 한다.
    // 1-c. 인접한 2개의 타일을 교환하여, 점수를 획득할 수 있는 방법이 최소 1가지 존재하여야 한다.
    while (true)
    {
        while (true)
        {
            int point = deleteTiles();

            if (point == 0)
            {
                break;
            }

            fillBoard();
        }

        calculateMaxScore();

        if (mRet[0] > 0)
        {
            break;
        }

        resetBoard();
    }

    // 2. 인접한 타일의 위치를 교환하여 타일을 삭제하고 점수를 얻는다.
    swap(board[mRet[1]][mRet[2]], board[mRet[3]][mRet[4]]);
    deleteTiles();
    fillBoard();

    // 3. 삭제 후 생긴 빈 공간을 채운다.
    while (true)
    {
        int score = deleteTiles();

        if (score == 0)
        {
            break;
        }

        fillBoard();
        mRet[0] += score;
    }

    return mRet;
}
