#include "../Header/Score.h"
#include <stdio.h>

Score::Score(const int &scoreType) : Entity()
{
    this->scoreType = scoreType;

    switch (scoreType)
    {
    case 0: // desenha pontuação
        this->setMidPoint(85, 94);
        this->score = 0;

        for (int i = 0; i < 9; i++) // textures[16 - 25] = {1,2,3,4,5,6,7,8,9,0}
            this->digitsScoreTextures[i + 1] = textures[i + 16];
        this->digitsScoreTextures[0] = textures[25];
        break;

    case 1: // desenha vida
        this->setMidPoint(-92, -92);
        this->score = 3;

        this->digitsScoreTextures[0] = textures[26];
        break;
    }
}

void Score::draw()
{
    double tamDig;
    switch (this->scoreType)
    {
    case 0:
        int dig[9];
        tamDig = 8;

        // printf("Score: %d\n", this->score);

        for (int i = 0; i < 9; i++)
        {
            dig[i] = 0;
            int aux = score / pow(10, i);
            dig[i] = aux % 10;

            glPushMatrix();
            glTranslatef(this->midPoint.getX() - tamDig * i,
                         this->midPoint.getY(),
                         0);

            switch (dig[i])
            {
                case 0:
                    glCallList(this->digitsScoreTextures[0]);
                    break;

                case 1:
                    glCallList(this->digitsScoreTextures[1]);
                    break;

                case 2:
                    glCallList(this->digitsScoreTextures[2]);
                    break;

                case 3:
                    glCallList(this->digitsScoreTextures[3]);
                    break;

                case 4:
                    glCallList(this->digitsScoreTextures[4]);
                    break;

                case 5:
                    glCallList(this->digitsScoreTextures[5]);
                    break;

                case 6:
                    glCallList(this->digitsScoreTextures[6]);
                    break;

                case 7:
                    glCallList(this->digitsScoreTextures[7]);
                    break;

                case 8:
                    glCallList(this->digitsScoreTextures[8]);
                    break;

                case 9:
                    glCallList(this->digitsScoreTextures[9]);
                    break;
            }
            glPopMatrix();
        }
        break;
        
    case 1:
        tamDig = 9;
        for (int i = score; i > 0; i--)
        {
            glPushMatrix();
            glTranslatef(this->midPoint.getX() + tamDig * i,
                         this->midPoint.getY(),
                         0);
            glCallList(this->digitsScoreTextures[0]);
            glPopMatrix();
        }
        break;
    }
}