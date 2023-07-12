#include "shapes.c"

int main(int argc, char*argv[])
{
    if (argc > 1)
    {
        if (strcmp(argv[1], "-o") == 0)
        {
            if(strcmp(argv[3], "-w") == 0 && strcmp(argv[5], "-h") == 0)
            {
                Image* img = image_new(atoi(argv[4]), atoi(argv[6]));
                const char carka[2] = ",";
                for (int i = 7; i < argc; i++)
                {
                    if (strcmp(argv[i], "-r") == 0 )
                    {
                        int tmp = i + 1;
                        int x = atoi(strtok(argv[tmp], carka));
                        int y = atoi(strtok(NULL, carka));
                        int w = atoi(strtok(NULL, carka));
                        int h = atoi(strtok(NULL, carka));
                        Pixel color = {(uchar)atoi(strtok(NULL, carka)), (uchar)atoi(strtok(NULL, carka)), (uchar)atoi(strtok(NULL, carka)), (uchar)atoi(strtok(NULL, carka))};
                        draw_rect(img, x, y, w, h, color);
                        i = i + 1;
                    }
                    else if (strcmp(argv[i], "-c") == 0 )
                    {
                        int tmp = i + 1;
                        int x = atoi(strtok(argv[tmp], carka));
                        int y = atoi(strtok(NULL, carka));
                        int p = atoi(strtok(NULL, carka));
                        Pixel color = {(uchar)atoi(strtok(NULL, carka)), (uchar)atoi(strtok(NULL, carka)), (uchar)atoi(strtok(NULL, carka)), (uchar)atoi(strtok(NULL, carka))};
                        draw_circle(img, x, y, p, color);
                        i = i + 1;
                    }
                    else if (strcmp(argv[i], "-t") == 0 )
                    {
                        int tmp = i + 1;
                        int x = atoi(strtok(argv[tmp], carka));
                        int y = atoi(strtok(NULL, carka));
                        int r = atoi(strtok(NULL, carka));
                        Pixel color = {(uchar)atoi(strtok(NULL, carka)), (uchar)atoi(strtok(NULL, carka)), (uchar)atoi(strtok(NULL, carka)), (uchar)atoi(strtok(NULL, carka))};
                        draw_triag(img, x, y, r, color);
                        i = i + 1;
                    }
                    else
                    {
                        printf("Nebyl zadán povolený tvar!\n");
                    }
                }
                image_write(img, argv[2]);
                image_free(img);
            }
        }
        else if (strcmp(argv[1], "-f") == 0)
        {
            FILE * soubor = fopen(argv[2],"r");
            char nazev[80];
            char buff[100];
            char buff2[100];
            char * tmp_nazev;
            char * tmp;
            char * tmp2;

            fgets(nazev, sizeof(nazev), soubor);
            tmp_nazev = nazev;

            const char mezera[2] = " ";

            fgets(buff, sizeof(buff), soubor);
            tmp = buff;
            tmp = strtok(buff, mezera);

            fgets(buff2, sizeof(buff2), soubor);
            tmp2 = buff2;
            tmp2 = strtok(buff2, mezera);

            if(strcmp(tmp, "-w") == 0 && strcmp(tmp2, "-h") == 0)
            {
                tmp = strtok(NULL, mezera);
                tmp2 = strtok(buff2, mezera);
                Image* img = image_new(atoi(tmp), atoi(tmp2));
                while (!feof(soubor))
                {
                    char radek[100];
                    char * radek_tmp;
                    fgets(radek, sizeof(radek), soubor);
                    radek_tmp = radek;
                    radek_tmp = strtok(radek, mezera);

                    if (strcmp(radek_tmp, "-r") == 0)
                    {
                        const char carka[2] = ",";
                        radek_tmp = strtok(NULL, mezera);
                        int x = atoi(strtok(radek_tmp, carka));
                        int y = atoi(strtok(NULL, carka));
                        int w = atoi(strtok(NULL, carka));
                        int h = atoi(strtok(NULL, carka));
                        Pixel color = {(uchar)atoi(strtok(NULL, carka)), (uchar)atoi(strtok(NULL, carka)), (uchar)atoi(strtok(NULL, carka)), (uchar)atoi(strtok(NULL, carka))};
                        draw_rect(img, x, y, w, h, color);
                    }
                    else if (strcmp(radek_tmp, "-c") == 0 )
                    {
                        const char carka[2] = ",";
                        radek_tmp = strtok(NULL, mezera);
                        int x = atoi(strtok(radek_tmp, carka));
                        int y = atoi(strtok(NULL, carka));
                        int p = atoi(strtok(NULL, carka));
                        Pixel color = {(uchar)atoi(strtok(NULL, carka)), (uchar)atoi(strtok(NULL, carka)), (uchar)atoi(strtok(NULL, carka)), (uchar)atoi(strtok(NULL, carka))};
                        draw_circle(img, x, y, p, color);
                    }
                    else if (strcmp(radek_tmp, "-t") == 0 )
                    {
                        const char carka[2] = ",";
                        radek_tmp = strtok(NULL, mezera);
                        int x = atoi(strtok(radek_tmp, carka));
                        int y = atoi(strtok(NULL, carka));
                        int r = atoi(strtok(NULL, carka));
                        Pixel color = {(uchar)atoi(strtok(NULL, carka)), (uchar)atoi(strtok(NULL, carka)), (uchar)atoi(strtok(NULL, carka)), (uchar)atoi(strtok(NULL, carka))};
                        draw_triag(img, x, y, r, color);
                    }
                }
                image_write(img, tmp_nazev);
                image_free(img);
            }
        }
    }
    else
    {
        printf("NEZADAL PARAMETRY!!!\n");
    }
    return 0;
}
