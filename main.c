#include <stdio.h>
#include <raylib.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


#define ROTATION_SPEED 17


int main() {

    /**
        **********************Chargement des musique du jeu******************************
        ********************************************************************************
    */

    InitAudioDevice();
    Music music = LoadMusicStream("images/obstacles/s1.mp3");
    PlayMusicStream(music);
    Music countDown = LoadMusicStream("images/obstacles/countdown.mp3");
    PlayMusicStream(countDown);
    Music songMoto = LoadMusicStream("images/obstacles/songMoto.mp3");
    PlayMusicStream(songMoto);


    ///Page d'acceuile du jeu
    Rectangle page = {0, -500, 1200, 1700};
    bool VisiblePage = true;
    bool Instructionpage = true;


    /**
        **************************Définition des dimensions de la fenêtre*********************************************
        *************************************************************************************************************
    */

    int width = 1300;
    int height = 1000;
    InitWindow(width, height, "Racing game");
    SetTargetFPS(60);


    ///fenêtre de fin
    Rectangle page_End = {0, 0, GetScreenWidth(), GetScreenHeight()};

    /**
        *************************************************definition des dimensions de l'aire de jeu**************************************
        ********************************************************************************************************************************
    */

    int world_width = 1700;
    int world_height = 35000;

    /**
        ***************************************************Chargement de la route**********************************************************
        ***********************************************************************************************************************************
    */

    Image soil_image = LoadImage("images/lignes/Road2.png");
    ImageRotateCW(&soil_image);
    Texture2D soil_texture = LoadTextureFromImage(soil_image);


    Image fire = LoadImage("obstacles/obstacles/fire.png");
    Texture2D fire_texture = LoadTextureFromImage(fire);


    /**
        ************************************************Chargement du drapeau, des lignes de départ et d'arrivée**********************************
        ******************************************************************************************************************************************
    */

    Image flag = LoadImage("images/lignes/flag.png");
    Texture2D flag_texture = LoadTextureFromImage(flag);

    Image start_line = LoadImage("images/lignes/end-line.png");
    Texture2D start_line_texture = LoadTextureFromImage(start_line);


    Image end_line = LoadImage("images/lignes/end-line.png");
    Texture2D end_line_texture = LoadTextureFromImage(end_line);




    /**
      *
      ************************************************************CHARGEMENT ET PARAMETRAGE DE LA PREMIERE MOTO **********************************
      ********************************************************************************************************************************************
    */

    Image moto_image = LoadImage("images/moto/moto.png");
    ImageRotateCW(&moto_image);
    Texture2D moto_texture = LoadTextureFromImage(moto_image);
    Rectangle moto_texture_rec = {
        .x = 0,
        .y = 0,
        .width = moto_texture.width,
        .height = moto_texture.height,
    };

    int moto_width = 140;
    int moto_height = 190;
    float moto_x = 580;
    float moto_y = 600;
    float moto_speed = 0;
    float moto_max_speed = 10;
    int moto_direction = -1;
    float moto_rotation = -90;
    float moto_speedup = 10;
    float moto_slowdown = 20;


    /**
      *
      REGLAGE DE LA CAMERA **
    */

    Camera2D camera = {
        .offset = (Vector2){0, 0},
        .target = (Vector2){0, 0},
        .rotation = 0,
        .zoom = 1.1,
    };
    Camera2D camera2 = {
        .offset = (Vector2){0, 0},
        .target = (Vector2){0, 0},
        .rotation = 0,
        .zoom = 1.1,
    };


    /** ******
        ********************************************************CHARGEMENT ET PARAMETRAGE DES OBSTACLES ***********************

        ****** *************************************************************************************************************************
    */


    Image ob1 = LoadImage("images/obstacles/ob1.png");
    Texture2D ob1_texture = LoadTextureFromImage(ob1);
    Image ob2 = LoadImage("images/obstacles/ob2.png");
    Texture2D ob2_texture = LoadTextureFromImage(ob2);
    Image ob3 = LoadImage("images/obstacles/ob3.png");
    Texture2D ob3_texture = LoadTextureFromImage(ob3);
    Image ob4 = LoadImage("images/obstacles/ob4.png");
    Texture2D ob4_texture = LoadTextureFromImage(ob4);
    Image ob5 = LoadImage("images/obstacles/ob5.png");
    Texture2D ob5_texture = LoadTextureFromImage(ob5);
    Image ob6 = LoadImage("images/obstacles/ob6.png");
    Texture2D ob6_texture = LoadTextureFromImage(ob6);
    Image ob7 = LoadImage("images/obstacles/ob7.png");
    Texture2D ob7_texture = LoadTextureFromImage(ob7);
    Image ob8 = LoadImage("images/obstacles/ob8.png");
    Texture2D ob8_texture = LoadTextureFromImage(ob8);
    Image ob9 = LoadImage("images/obstacles/ob9.png");
    Texture2D ob9_texture = LoadTextureFromImage(ob9);
    Image ob10 = LoadImage("images/obstacles/ob10.png");
    Texture2D ob10_texture = LoadTextureFromImage(ob10);
    Image ob11 = LoadImage("images/obstacles/ob11.png");
    Texture2D ob11_texture = LoadTextureFromImage(ob11);
    Image ob12 = LoadImage("images/obstacles/ob12.png");
    Texture2D ob12_texture = LoadTextureFromImage(ob12);
    Image ob13 = LoadImage("images/obstacles/ob13.png");
    Texture2D ob13_texture = LoadTextureFromImage(ob13);

    Rectangle ob1_texture_rec = {.x = 0, .y = 0, .width = ob1_texture.width, .height = ob1_texture.height,};
    Rectangle ob3_texture_rec = {.x = 0, .y = 0, .width = ob3_texture.width, .height = ob3_texture.height,};
    Rectangle ob4_texture_rec = {.x = 0, .y = 0, .width = ob4_texture.width, .height = ob4_texture.height,};
    Rectangle ob5_texture_rec = {.x = 0, .y = 0, .width = ob5_texture.width, .height = ob5_texture.height,};
    Rectangle ob6_texture_rec = {.x = 0, .y = 0, .width = ob6_texture.width, .height = ob6_texture.height,};
    Rectangle ob7_texture_rec = {.x = 0, .y = 0, .width = ob7_texture.width, .height = ob7_texture.height,};
    Rectangle ob8_texture_rec = {.x = 0, .y = 0, .width = ob8_texture.width, .height = ob8_texture.height,};
    Rectangle ob9_texture_rec = {.x = 0, .y = 0, .width = ob9_texture.width, .height = ob9_texture.height,};
    Rectangle ob10_texture_rec = {.x = 0, .y = 0, .width = ob10_texture.width, .height = ob10_texture.height,};
    Rectangle ob11_texture_rec = {.x = 0, .y = 0, .width = ob11_texture.width, .height = ob11_texture.height,};
    Rectangle ob13_texture_rec = {.x = 0, .y = 0, .width = ob13_texture.width, .height = ob13_texture.height,};



    float x1 = 530, x2=355, x3=385, x4=490, x5=240, x6=250, x7=500, x8=510, x9=995, x10=1005, x11=760, x12=840;
    float y1 = -1000, y2=-2000, y3=-3000, y4=-5000, y5=-6000, y7=-7000, y8=-8000, y9=-9500, y10=-11000, y11=-12000, y12=-13000, y13=-13800, y14=-14000, y15=-15000, y16=-15900, y17=-16500, y18=-18000, y19=-18500, y20=-19800, y21=-21000, y22=- 22000;
    float y23=22800, y24=-23000, y25=-24000, y26=-24800, y27=-25500, y28=-26500, y29=-27600, y30=-28500, y31=-29300, y32=-1800, y33=-3800, y34=-6800, y35=-8700, y36=-9200, y37=-14800, y38=-19000, y39=-27000;
    float y42 = -28000, y43 = - 30000, y44 = -32000, y45 = -31000, y46 = -31500;


    /**
        ****************************************Chargement des pièces de récompenses*************************************
        ****************************************************************************************************************
    */

    Image p5 = LoadImage("images/pieces/p5.png");
    Texture2D p5_texture = LoadTextureFromImage(p5);
    Image p6 = LoadImage("images/pieces/p6.png");
    Texture2D p6_texture = LoadTextureFromImage(p6);
    Image p7 = LoadImage("images/pieces/p7.png");
    Texture2D p7_texture = LoadTextureFromImage(p7);
    Image p8 = LoadImage("images/pieces/p8.png");
    Texture2D p8_texture = LoadTextureFromImage(p8);

    Rectangle piece5_texture_rec = {.x = 0, .y = 0, .width = p5_texture.width, .height = p5_texture.height,};
    Rectangle piece6_texture_rec = {.x = 0, .y = 0, .width = p6_texture.width, .height = p6_texture.height,};
    Rectangle piece7_texture_rec = {.x = 0, .y = 0, .width = p7_texture.width, .height = p7_texture.height,};
    Rectangle piece8_texture_rec = {.x = 0, .y = 0, .width = p8_texture.width, .height = p8_texture.height,};

    //1ere vague de disposition
    float px = 700;
    float py[13];
    int i;
    py[0] = 0;
    for(i = 0; i < 13; i++){
        py[i+1] = py[i]-200;
    }

    //2e vague
    float px2 = 1000;
    float py2[13];
    py2[0] = -3000;
    for(i = 0; i < 13; i++){
        py2[i+1] = py2[i]-200;
    }

    //3e vague
    float py3[10];
    py3[0] = -6000;
    for(i = 0; i < 10; i++){
        py3[i+1] = py3[i]-200;
    }

    //4e vague
    float py4[10];
    py4[0] = -8000;
    for(i = 0; i < 10; i++){
        py4[i+1] = py4[i]-200;
    }

    //5e vague
    float px3 = 750;
    float py5[10];
    py5[0] = -10500;
    for(i = 0; i < 10; i++){
        py5[i+1] = py5[i]-200;
    }

    //6e vague
    float py6[10];
    py6[0] = -13000;
    for(i = 0; i < 10; i++){
        py6[i+1] = py6[i]-200;
    }

    //7e vague
    float py7[10];
    py7[0] = -15500;
    for(i = 0; i < 10; i++){
        py7[i+1] = py7[i]-200;
    }

    //8e vague
    float py8[10];
    py8[0] = -18000;
    for(i = 0; i < 10; i++){
        py8[i+1] = py8[i]-200;
    }

    //9e vague
    float py9[10];
    py9[0] = -20500;
    for(i = 0; i < 10; i++){
        py9[i+1] = py9[i]-200;
    }

    //10e vague
    float py10[10];
    py10[0] = -23000;
    for(i = 0; i < 10; i++){
        py10[i+1] = py10[i]-200;
    }

     //11e vague
    float py11[10];
    py11[0] = -26000;
    for(i = 0; i < 10; i++){
        py11[i+1] = py11[i]-200;
    }

    //12e vague
    float py12[10];
    py12[0] = -28000;
    for(i = 0; i < 10; i++){
        py12[i+1] = py12[i]-200;
    }

    //13e vague
    float px4 = 200;
    float py13[10];
    py13[0] = -3000;
    for(i = 0; i < 10; i++){
        py13[i+1] = py13[i]-200;
    }

    //14e vague
    float px5 = 550;
    float py14[10];
    py14[0] = -4500;
    for(i = 0; i < 10; i++){
        py14[i+1] = py14[i]-200;
    }

    //15e vague
    float py15[10];
    py15[0] = -8500;
    for(i = 0; i < 10; i++){
        py15[i+1] = py15[i]-200;
    }

    //16e vague
    float py16[10];
    py16[0] = -11000;
    for(i = 0; i < 10; i++){
        py16[i+1] = py16[i]-200;
    }

    //17e vague
    float py17[10];
    py17[0] = -13000;
    for(i = 0; i < 10; i++){
        py17[i+1] = py17[i]-200;
    }

    //18e vague
    float py18[10];
    py18[0] = -16000;
    for(i = 0; i < 10; i++){
        py18[i+1] = py18[i]-200;
    }

    //19e vague
    float py19[10];
    py19[0] = -18500;
    for(i = 0; i < 10; i++){
        py19[i+1] = py19[i]-200;
    }

    //20e vague
    float py20[10];
    py20[0] = -19000;
    for(i = 0; i < 10; i++){
        py20[i+1] = py20[i]-200;
    }

    //21e vague
    float py21[10];
    py21[0] = -22500;
    for(i = 0; i < 10; i++){py21[i+1] = py21[i]-200;}

    //22e vague
    float py22[10];
    py22[0] = -25000;
    for(i = 0; i < 10; i++){py22[i+1] = py22[i]-200;}

    //23e vague
    float py23[10];
    float px6 = 470;
    py23[0] = -28000;
    for(i = 0; i < 10; i++){py23[i+1] = py23[i]-200;}


    ///INITIALISATION DU COMPTE A REBOURS ET DU CHRONOMETRE
    int cpt = 3; //durée du compte à rebours
    float elapsedTime = 0;
    bool controlcpt = true;

    int ms = 0;
    int s = 0;
    int mn = 0;
    int h = 0;
    float time = 0;
    bool raceOver = false;
    bool move = false; // indiquera si la moto se deplace

    ///booléen pour la gestion des pauses dans le jeu
    bool pause = false;
    bool action = false;

    ///Booléen pour la gestion des bonus
    bool bonus1 = false,bonus2 = false,bonus3 = false,bonus4 = false,bonus5 = false,bonus6 = false,bonus7 = false,bonus8 = false,bonus9 = false,bonus10 = false,bonus11 = false,bonus12 = false,bonus13 = false,bonus14 = false,bonus15 = false,bonus16 = false,bonus17 = false,bonus18 = false;
    bool bonus19 = false,bonus20 = false,bonus21 = false, bonus22 = false,bonus23 = false,bonus24 = false,bonus25 = false,bonus26 = false,bonus27 = false,bonus28 = false,bonus29 = false,bonus30 = false,bonus31 = false,bonus32 = false,bonus33 = false,bonus34 = false,bonus35 = false,bonus36 = false;
    bool bonus37 = false,bonus38 = false,bonus39 = false,bonus40 = false,bonus41 = false,bonus42 = false,bonus43 = false,bonus44 = false,bonus45 = false,bonus46 = false,bonus47 = false,bonus48 = false,bonus49 = false,bonus50 = false,bonus51 = false,bonus52 = false,bonus53 = false,bonus54 = false;
    bool bonus55 = false,bonus56 = false,bonus57 = false,bonus58 = false,bonus59 = false,bonus60 = false,bonus61 = false,bonus62 = false,bonus63 = false,bonus64 = false,bonus65 = false,bonus66 = false,bonus67 = false,bonus68 = false,bonus69 = false,bonus70 = false,bonus71 = false,bonus72 = false;
    bool bonus73 = false,bonus74 = false,bonus75 = false,bonus76 = false,bonus77 = false,bonus78 = false,bonus79 = false,bonus80 = false,bonus81 = false,bonus82 = false,bonus83 = false,bonus84 = false,bonus85 = false,bonus86 = false,bonus87 = false,bonus88 = false,bonus89 = false,bonus90 = false;
    bool bonus91 = false,bonus92 = false,bonus93 = false,bonus94 = false,bonus95 = false,bonus96 = false,bonus97 = false,bonus98 = false,bonus99 = false,bonus100 = false,bonus101 = false,bonus102 = false,bonus103 = false,bonus104 = false,bonus105 = false,bonus106 = false,bonus107 = false,bonus108 = false;
    bool bonus109 = false,bonus110 = false,bonus111 = false,bonus112 = false,bonus113 = false,bonus114 = false,bonus115 = false,bonus116 = false,bonus117 = false,bonus118 = false,bonus119 = false,bonus120 = false,bonus121 = false,bonus122 = false,bonus123 = false,bonus124 = false,bonus125 = false,bonus126 = false;
    bool bonus127 = false,bonus128 = false,bonus129 = false,bonus130 = false,bonus131 = false,bonus132 = false,bonus133 = false,bonus134 = false,bonus135 = false,bonus136 = false,bonus137 = false,bonus138 = false,bonus139 = false,bonus140 = false,bonus141 = false,bonus142 = false,bonus143 = false,bonus144 = false;
    bool bonus145 = false,bonus146 = false,bonus147 = false,bonus148 = false,bonus149 = false,bonus150 = false,bonus151 = false,bonus152 = false,bonus153 = false,bonus154 = false,bonus155 = false,bonus156 = false,bonus157 = false,bonus158 = false,bonus159 = false,bonus160 = false,bonus161 = false,bonus162 = false;
    bool bonus163 = false,bonus164 = false,bonus165 = false,bonus166 = false,bonus167 = false,bonus168 = false,bonus169 = false,bonus170 = false,bonus171 = false,bonus172 = false,bonus173 = false,bonus174 = false,bonus175 = false,bonus176 = false,bonus177 = false,bonus178 = false,bonus179 = false,bonus180 = false;
    bool bonus181 = false,bonus182 = false,bonus183 = false,bonus184 = false,bonus185 = false,bonus186 = false,bonus187 = false,bonus188 = false,bonus189 = false,bonus190 = false,bonus191 = false,bonus192 = false,bonus193 = false,bonus194 = false,bonus195 = false,bonus196 = false,bonus197 = false,bonus198 = false;
    bool bonus199 = false,bonus200 = false,bonus201 = false,bonus202 = false,bonus203 = false,bonus204 = false,bonus205 = false,bonus206 = false,bonus207 = false,bonus208 = false,bonus209 = false,bonus210 = false,bonus211 = false,bonus213 = false,bonus212 = false,bonus214 = false,bonus215 = false,bonus216 = false;
    bool bonus217 = false,bonus218 = false,bonus219 = false,bonus220 = false,bonus221 = false,bonus222 = false,bonus223 = false,bonus224 = false,bonus225 = false,bonus227 = false,bonus226 = false,bonus228 = false,bonus229 = false,bonus230 = false,bonus231 = false,bonus232 = false,bonus233 = false,bonus234 = false;
    bool bonus235 = false,bonus236 = false;



    int score = 0;
    bool collision = false;

    /**
        ***********************************************DEBUT DU JEU**************************************************************************************
        *************************************************************************************************************************************************
    */

    while( ! WindowShouldClose() ) {

        float dt = GetFrameTime();


        if( IsKeyDown( KEY_ENTER) ) {
            VisiblePage = false;
        }
        if( IsKeyDown( KEY_A) ) {
            Instructionpage = false;
        }



        BeginDrawing();
        ClearBackground(WHITE);

        BeginMode2D(camera);
        ///AFFICHAGE DE LA PAGE D'ACCEUIL
        if(VisiblePage){
            DrawRectangleRec(page, ORANGE);
            DrawText("RACING", GetScreenWidth() / 3.5, GetScreenHeight() / 6, 100, WHITE);
            DrawText("GAME", GetScreenWidth() / 3.1, GetScreenHeight() / 4, 100, WHITE);
            DrawText("PRESS ENTER TO PLAY", GetScreenWidth() -1100, GetScreenHeight() -300, 60, WHITE);
            UpdateMusicStream(music);
        }

        ///AFFICHAGE DE LA PAGE D'INSTRUCTIONS
        if(!VisiblePage){
            PauseMusicStream(music);
            DrawRectangleRec(page, ORANGE);
            DrawText("Instructions", 450, 50, 50, WHITE);
            DrawText("- Pick up the coins", 50, 150, 30, WHITE);
            DrawText("- Avoid obstacles", 50, 200, 30, WHITE);
            DrawText("- Press KEY_UP to accelerate", 50, 250, 30, WHITE);
            DrawText("- Press KEY_DOWN to slow down", 50, 300, 30, WHITE);
            DrawText("- Press KEY_LEFT  and KEY_RIGTH to turn", 50, 350, 30, WHITE);
            DrawText("- Press BAR SPACE to pause", 50, 400, 30, WHITE);
            DrawText("- Press M to resume", 50, 450, 30, WHITE);
            DrawText("PRESS A TO PASS >>", GetScreenWidth() -1000, GetScreenHeight() -200, 60, WHITE);
            UpdateMusicStream(music);
        }



        ///DEFINITION DES RECTANGLES AUTOUR DES OBSTACLES POUR GERER LES COLLISIONS

            Rectangle ob1_rec = {.x = x11,.y = y42,.width = 200,.height = 328,};
            Rectangle ob2_rec = {.x = x2,.y = y2,.width = 280,.height = 592,};
            Rectangle ob3_rec = {.x = x3,.y = y3,.width = 280,.height = 592,};
            Rectangle ob5_rec = {.x = x4,.y = y4,.width = 250,.height = 360,};
            Rectangle ob6_rec = {.x = x5,.y = y5,.width = 250,.height = 340,};
            Rectangle ob7_rec = {.x = x6,.y = y7,.width = 250,.height = 367,};
            Rectangle ob8_rec = {.x = x7,.y = y7,.width = 250,.height = 350,};
            Rectangle ob9_rec = {.x = x6,.y = y8,.width = 280,.height = 592,};
            Rectangle ob10_rec = {.x = x3,.y = y9,.width = 280,.height = 592,};
            Rectangle ob11_rec = {.x = x7,.y = y10,.width = 250,.height = 780,};
            Rectangle ob12_rec = {.x = x3,.y = y11,.width = 280,.height = 592,};
            Rectangle ob13_rec = {.x = x7,.y = y12,.width = 250,.height = 555,};
            Rectangle ob14_rec = {.x = 250,.y = y12,.width = 250,.height = 360,};
            Rectangle ob15_rec = {.x = 470,.y = y13,.width = 280,.height = 592,};
            Rectangle ob16_rec = {.x = 250,.y = y14,.width = 200,.height = 328,};
            Rectangle ob17_rec = {.x = x5,.y = y15,.width = 250,.height = 350,};
            Rectangle ob18_rec = {.x = x3,.y = y16,.width = 250,.height = 780,};
            Rectangle ob19_rec = {.x = x1,.y = y17,.width = 200,.height = 320,};
            Rectangle ob20_rec = {.x = x1,.y = y18,.width = 200,.height = 328,};
            Rectangle ob21_rec = {.x = x5,.y = y19,.width = 280,.height = 592,};
            Rectangle ob22_rec = {.x = x1,.y = y20,.width = 200,.height = 328,};
            Rectangle ob23_rec = {.x = 230,.y = y21,.width = 300,.height = 578,};
            Rectangle ob24_rec = {.x = 230,.y = y22,.width = 280,.height = 592,};
            Rectangle ob25_rec = {.x = x7,.y = y23,.width = 280,.height = 550,};
            Rectangle ob26_rec = {.x = x5,.y = y24,.width = 280,.height = 592,};
            Rectangle ob27_rec = {.x = 590,.y = y25,.width = 280,.height = 592,};
            Rectangle ob28_rec = {.x = x1,.y = y26,.width = 200,.height = 328,};
            Rectangle ob29_rec = {.x = 470,.y = y27,.width = 280,.height = 592,};
            Rectangle ob30_rec = {.x = 250,.y = y28,.width = 200,.height = 320,};
            Rectangle ob31_rec = {.x = 230,.y = y29,.width = 250,.height = 780,};
            Rectangle ob32_rec = {.x = 385,.y = y30,.width = 280,.height = 592,};
            Rectangle ob33_rec = {.x = 250,.y = y31,.width = 250,.height = 360,};
            Rectangle ob34_rec = {.x = x9,.y = y1,.width = 250,.height = 555,};
            Rectangle ob35_rec = {.x = x10,.y = y32,.width = 200,.height = 320,};
            Rectangle ob36_rec = {.x = 1085,.y = y3,.width = 280,.height = 592,};
            Rectangle ob38_rec = {.x = x11,.y = y4,.width = 230,.height = 360,};
            Rectangle ob39_rec = {.x = x9,.y = y5,.width = 250,.height = 367,};
            Rectangle ob40_rec = {.x = x9,.y = y34,.width = 250,.height = 350,};
            Rectangle ob41_rec = {.x = 965,.y = y8,.width = 280,.height = 592,};
            Rectangle ob42_rec = {.x = x12,.y = y35,.width = 280,.height = 592,};
            Rectangle ob43_rec = {.x = x9,.y = y36,.width = 250,.height = 340,};
            Rectangle ob44_rec = {.x = x11,.y = y11,.width = 250,.height = 350,};
            Rectangle ob45_rec = {.x = x10,.y = y43,.width = 200,.height = 328,};
            Rectangle ob46_rec = {.x = 960,.y = y37,.width = 280,.height = 592,};
            Rectangle ob47_rec = {.x = x10,.y = y16,.width = 200,.height = 328,};
            Rectangle ob48_rec = {.x = 880,.y = y18,.width = 280,.height = 610,};
            Rectangle ob49_rec = {.x = x11,.y = y38,.width = 250,.height = 780,};
            Rectangle ob50_rec = {.x = x11,.y = y21,.width = 250,.height = 555,};
            Rectangle ob51_rec = {.x = x10,.y = y23,.width = 200,.height = 328,};
            Rectangle ob52_rec = {.x = 1100,.y = y25,.width = 250,.height = 592,};
            Rectangle ob53_rec = {.x = x11,.y = y27,.width = 250,.height = 555,};
            Rectangle ob54_rec = {.x = x9,.y = y39,.width = 250,.height = 780,};
            Rectangle ob55_rec = {.x = x8,.y = y43,.width = 280,.height = 592,};
            Rectangle ob56_rec = {.x = x4,.y = y44,.width = 250,.height = 340,};
            Rectangle ob57_rec = {.x = x5,.y = y45,.width = 200,.height = 328,};
            Rectangle ob58_rec = {.x = x12,.y = y45,.width = 280,.height = 592,};
            Rectangle ob59_rec = {.x = x9,.y = y46,.width = 250,.height = 780,};


            ///DEFINITION DES RECTANGLES AUTOUR DES PIECES
            Rectangle p1_rec = {.x = px,.y = py[0],.width = piece5_texture_rec.width,.height = piece5_texture_rec.height,};
            Rectangle p2_rec = {.x = px,.y = py[1],.width = piece5_texture_rec.width,.height = piece5_texture_rec.height,};
            Rectangle p3_rec = {.x = px,.y = py[2],.width = piece5_texture_rec.width,.height = piece5_texture_rec.height,};
            Rectangle p4_rec = {.x = px,.y = py[3],.width = piece7_texture_rec.width,.height = piece7_texture_rec.height,};
            Rectangle p5_rec = {.x = px,.y = py[4],.width = piece7_texture_rec.width,.height = piece7_texture_rec.height,};
            Rectangle p6_rec = {.x = px,.y = py[5],.width = piece8_texture_rec.width,.height = piece8_texture_rec.height,};
            Rectangle p7_rec = {.x = px,.y = py[6],.width = piece8_texture_rec.width,.height = piece8_texture_rec.height,};
            Rectangle p8_rec = {.x = px,.y = py[7],.width = piece8_texture_rec.width,.height = piece8_texture_rec.height,};
            Rectangle p9_rec = {.x = px,.y = py[8],.width = piece7_texture_rec.width,.height = piece7_texture_rec.height,};
            Rectangle p10_rec = {.x = px,.y = py[9],.width = piece6_texture_rec.width,.height = piece6_texture_rec.height,};

            Rectangle p14_rec = {.x = px2,.y = py2[0],.width = piece5_texture_rec.width,.height = piece5_texture_rec.height,};
            Rectangle p15_rec = {.x = px2,.y = py2[1],.width = piece6_texture_rec.width,.height = piece6_texture_rec.height,};
            Rectangle p16_rec = {.x = px2,.y = py2[2],.width = piece7_texture_rec.width,.height = piece7_texture_rec.height,};
            Rectangle p17_rec = {.x = px2,.y = py2[3],.width = piece8_texture_rec.width,.height = piece8_texture_rec.height,};
            Rectangle p18_rec = {.x = px2,.y = py2[4],.width = piece5_texture_rec.width,.height = piece5_texture_rec.height,};
            Rectangle p19_rec = {.x = px2,.y = py2[5],.width = piece6_texture_rec.width,.height = piece6_texture_rec.height,};
            Rectangle p20_rec = {.x = px2,.y = py2[6],.width = piece7_texture_rec.width,.height = piece7_texture_rec.height,};
            Rectangle p21_rec = {.x = px2,.y = py2[7],.width = piece8_texture_rec.width,.height = piece8_texture_rec.height,};
            Rectangle p22_rec = {.x = px2,.y = py2[8],.width = piece8_texture_rec.width,.height = piece8_texture_rec.height,};
            Rectangle p23_rec = {.x = px2,.y = py2[9],.width = piece6_texture_rec.width,.height = piece6_texture_rec.height,};


            Rectangle p27_rec = p1_rec; p27_rec.y = py3[0];
            Rectangle p28_rec = p2_rec; p28_rec.y = py3[1];
            Rectangle p29_rec = p3_rec; p29_rec.y = py3[2];
            Rectangle p30_rec = p4_rec; p30_rec.y = py3[3];
            Rectangle p31_rec = p5_rec; p31_rec.y = py3[4];
            Rectangle p32_rec = p6_rec; p32_rec.y = py3[5];
            Rectangle p33_rec = p7_rec; p33_rec.y = py3[6];
            Rectangle p34_rec = p8_rec; p34_rec.y = py3[7];
            Rectangle p35_rec = p9_rec; p35_rec.y = py3[8];
            Rectangle p36_rec = p10_rec; p36_rec.y = py3[9];

            Rectangle p37_rec = p14_rec; p37_rec.y = py4[0];
            Rectangle p38_rec = p15_rec; p38_rec.y = py4[1];
            Rectangle p39_rec = p16_rec; p39_rec.y = py4[2];
            Rectangle p40_rec = p17_rec; p40_rec.y = py4[3];
            Rectangle p41_rec = p18_rec; p41_rec.y = py4[4];
            Rectangle p42_rec = p19_rec; p42_rec.y = py4[5];
            Rectangle p43_rec = p20_rec; p43_rec.y = py4[6];
            Rectangle p44_rec = p21_rec; p44_rec.y = py4[7];
            Rectangle p45_rec = p22_rec; p45_rec.y = py4[8];
            Rectangle p46_rec = p23_rec; p46_rec.y = py4[9];

            Rectangle p47_rec = p14_rec; p47_rec.y = py5[0]; p47_rec.x = px3;
            Rectangle p48_rec = p15_rec; p48_rec.y = py5[1]; p48_rec.x = px3;
            Rectangle p49_rec = p16_rec; p49_rec.y = py5[2]; p49_rec.x = px3;
            Rectangle p50_rec = p17_rec; p50_rec.y = py5[3]; p50_rec.x = px3;
            Rectangle p51_rec = p18_rec; p51_rec.y = py5[4]; p51_rec.x = px3;
            Rectangle p52_rec = p19_rec; p52_rec.y = py5[5]; p52_rec.x = px3;
            Rectangle p53_rec = p20_rec; p53_rec.y = py5[6]; p53_rec.x = px3;
            Rectangle p54_rec = p21_rec; p54_rec.y = py5[7]; p54_rec.x = px3;
            Rectangle p55_rec = p22_rec; p55_rec.y = py5[8]; p55_rec.x = px3;
            Rectangle p56_rec = p23_rec; p56_rec.y = py5[9]; p56_rec.x = px3;

            Rectangle p57_rec = p1_rec; p57_rec.y = py6[0];//
            Rectangle p58_rec = p2_rec; p58_rec.y = py6[1];
            Rectangle p59_rec = p3_rec; p59_rec.y = py6[2];
            Rectangle p60_rec = p4_rec; p60_rec.y = py6[3];
            Rectangle p61_rec = p5_rec; p61_rec.y = py6[4];
            Rectangle p62_rec = p6_rec; p62_rec.y = py6[5];
            Rectangle p63_rec = p7_rec; p63_rec.y = py6[6];
            Rectangle p64_rec = p8_rec; p64_rec.y = py6[7];
            Rectangle p65_rec = p9_rec; p65_rec.y = py6[8];
            Rectangle p66_rec = p10_rec; p66_rec.y = py6[9];

            Rectangle p67_rec = p14_rec; p67_rec.y = py7[0];
            Rectangle p68_rec = p15_rec; p68_rec.y = py7[1];
            Rectangle p69_rec = p16_rec; p69_rec.y = py7[2];
            Rectangle p70_rec = p17_rec; p70_rec.y = py7[3];
            Rectangle p71_rec = p18_rec; p71_rec.y = py7[4];
            Rectangle p72_rec = p19_rec; p72_rec.y = py7[5];
            Rectangle p73_rec = p20_rec; p73_rec.y = py7[6];
            Rectangle p74_rec = p21_rec; p74_rec.y = py7[7];
            Rectangle p75_rec = p22_rec; p75_rec.y = py7[8];
            Rectangle p76_rec = p23_rec; p76_rec.y = py7[9];

            Rectangle p77_rec = p14_rec; p77_rec.y = py8[0];
            Rectangle p78_rec = p15_rec; p78_rec.y = py8[1];
            Rectangle p79_rec = p16_rec; p79_rec.y = py8[2];
            Rectangle p80_rec = p17_rec; p80_rec.y = py8[3];
            Rectangle p81_rec = p18_rec; p81_rec.y = py8[4];
            Rectangle p82_rec = p19_rec; p82_rec.y = py8[5];
            Rectangle p83_rec = p20_rec; p83_rec.y = py8[6];
            Rectangle p84_rec = p21_rec; p84_rec.y = py8[7];
            Rectangle p85_rec = p22_rec; p85_rec.y = py8[8];
            Rectangle p86_rec = p23_rec; p86_rec.y = py8[9];

            Rectangle p87_rec = p1_rec; p87_rec.y = py9[0];
            Rectangle p88_rec = p2_rec; p88_rec.y = py9[1];
            Rectangle p89_rec = p3_rec; p89_rec.y = py9[2];
            Rectangle p90_rec = p4_rec; p90_rec.y = py9[3];
            Rectangle p91_rec = p5_rec; p91_rec.y = py9[4];
            Rectangle p92_rec = p6_rec; p92_rec.y = py9[5];
            Rectangle p93_rec = p7_rec; p93_rec.y = py9[6];
            Rectangle p94_rec = p8_rec; p94_rec.y = py9[7];
            Rectangle p95_rec = p9_rec; p95_rec.y = py9[8];
            Rectangle p96_rec = p10_rec; p96_rec.y = py9[9];

            Rectangle p97_rec = p14_rec; p97_rec.y = py10[0];
            Rectangle p98_rec = p15_rec; p98_rec.y = py10[1];
            Rectangle p99_rec = p16_rec; p99_rec.y = py10[2];
            Rectangle p100_rec = p17_rec; p100_rec.y = py10[3];
            Rectangle p101_rec = p18_rec; p101_rec.y = py10[4];
            Rectangle p102_rec = p19_rec; p102_rec.y = py10[5];
            Rectangle p103_rec = p20_rec; p103_rec.y = py10[6];
            Rectangle p104_rec = p21_rec; p104_rec.y = py10[7];
            Rectangle p105_rec = p22_rec; p105_rec.y = py10[8];
            Rectangle p106_rec = p23_rec; p106_rec.y = py10[9];

            Rectangle p107_rec = p1_rec; p107_rec.y = py11[0];
            Rectangle p108_rec = p2_rec; p108_rec.y = py11[1];
            Rectangle p109_rec = p3_rec; p109_rec.y = py11[2];
            Rectangle p110_rec = p4_rec; p110_rec.y = py11[3];
            Rectangle p111_rec = p5_rec; p111_rec.y = py11[4];
            Rectangle p112_rec = p6_rec; p112_rec.y = py11[5];
            Rectangle p113_rec = p7_rec; p113_rec.y = py11[6];
            Rectangle p114_rec = p8_rec; p114_rec.y = py11[7];
            Rectangle p115_rec = p9_rec; p115_rec.y = py11[8];
            Rectangle p116_rec = p10_rec; p116_rec.y = py11[9];

            Rectangle p117_rec = p14_rec; p117_rec.y = py12[0];
            Rectangle p118_rec = p15_rec; p118_rec.y = py12[1];
            Rectangle p119_rec = p16_rec; p119_rec.y = py12[2];
            Rectangle p120_rec = p17_rec; p120_rec.y = py12[3];
            Rectangle p121_rec = p18_rec; p121_rec.y = py12[4];
            Rectangle p122_rec = p19_rec; p122_rec.y = py12[5];
            Rectangle p123_rec = p20_rec; p123_rec.y = py12[6];
            Rectangle p124_rec = p21_rec; p124_rec.y = py12[7];
            Rectangle p125_rec = p22_rec; p125_rec.y = py12[8];
            Rectangle p126_rec = p23_rec; p126_rec.y = py12[9];
       //13
            Rectangle p127_rec = p14_rec; p127_rec.y = py13[0]; p127_rec.x = px4;
            Rectangle p128_rec = p15_rec; p128_rec.y = py13[1]; p128_rec.x = px4;
            Rectangle p129_rec = p16_rec; p129_rec.y = py13[2]; p129_rec.x = px4;
            Rectangle p130_rec = p17_rec; p130_rec.y = py13[3]; p130_rec.x = px4;
            Rectangle p131_rec = p18_rec; p131_rec.y = py13[4]; p131_rec.x = px4;
            Rectangle p132_rec = p19_rec; p132_rec.y = py13[5]; p132_rec.x = px4;
            Rectangle p133_rec = p20_rec; p133_rec.y = py13[6]; p133_rec.x = px4;
            Rectangle p134_rec = p21_rec; p134_rec.y = py13[7]; p134_rec.x = px4;
            Rectangle p135_rec = p22_rec; p135_rec.y = py13[8]; p135_rec.x = px4;
            Rectangle p136_rec = p23_rec; p136_rec.y = py13[9]; p136_rec.x = px4;

            Rectangle p137_rec = p14_rec; p137_rec.y = py14[0]; p137_rec.x = px5;
            Rectangle p138_rec = p15_rec; p138_rec.y = py14[1]; p138_rec.x = px5;
            Rectangle p139_rec = p16_rec; p139_rec.y = py14[2]; p139_rec.x = px5;
            Rectangle p140_rec = p17_rec; p140_rec.y = py14[3]; p140_rec.x = px5;
            Rectangle p141_rec = p18_rec; p141_rec.y = py14[4]; p141_rec.x = px5;
            Rectangle p142_rec = p19_rec; p142_rec.y = py14[5]; p142_rec.x = px5;
            Rectangle p143_rec = p20_rec; p143_rec.y = py14[6]; p143_rec.x = px5;
            Rectangle p144_rec = p21_rec; p144_rec.y = py14[7]; p144_rec.x = px5;
            Rectangle p145_rec = p22_rec; p145_rec.y = py14[8]; p145_rec.x = px5;
            Rectangle p146_rec = p23_rec; p146_rec.y = py14[9]; p146_rec.x = px5;

            Rectangle p147_rec = p14_rec; p147_rec.y = py15[0]; p147_rec.x = px4;
            Rectangle p148_rec = p15_rec; p148_rec.y = py15[1]; p148_rec.x = px4;
            Rectangle p149_rec = p16_rec; p149_rec.y = py15[2]; p149_rec.x = px4;
            Rectangle p150_rec = p17_rec; p150_rec.y = py15[3]; p150_rec.x = px4;
            Rectangle p151_rec = p18_rec; p151_rec.y = py15[4]; p151_rec.x = px4;
            Rectangle p152_rec = p19_rec; p152_rec.y = py15[5]; p152_rec.x = px4;
            Rectangle p153_rec = p20_rec; p153_rec.y = py15[6]; p153_rec.x = px4;
            Rectangle p154_rec = p21_rec; p154_rec.y = py15[7]; p154_rec.x = px4;
            Rectangle p155_rec = p22_rec; p155_rec.y = py15[8]; p155_rec.x = px4;
            Rectangle p156_rec = p23_rec; p156_rec.y = py15[9]; p156_rec.x = px4;

            Rectangle p157_rec = p14_rec; p157_rec.y = py16[0]; p157_rec.x = px4;
            Rectangle p158_rec = p15_rec; p158_rec.y = py16[1]; p158_rec.x = px4;
            Rectangle p159_rec = p16_rec; p159_rec.y = py16[2]; p159_rec.x = px4;
            Rectangle p160_rec = p17_rec; p160_rec.y = py16[3]; p160_rec.x = px4;
            Rectangle p161_rec = p18_rec; p161_rec.y = py16[4]; p161_rec.x = px4;
            Rectangle p162_rec = p19_rec; p162_rec.y = py16[5]; p162_rec.x = px4;
            Rectangle p163_rec = p20_rec; p163_rec.y = py16[6]; p163_rec.x = px4;
            Rectangle p164_rec = p21_rec; p164_rec.y = py16[7]; p164_rec.x = px4;
            Rectangle p165_rec = p22_rec; p165_rec.y = py16[8]; p165_rec.x = px4;
            Rectangle p166_rec = p23_rec; p166_rec.y = py16[9]; p166_rec.x = px4;

            Rectangle p167_rec = p14_rec; p167_rec.y = py17[0]; p167_rec.x = px5;
            Rectangle p168_rec = p15_rec; p168_rec.y = py17[1]; p168_rec.x = px5;
            Rectangle p169_rec = p16_rec; p169_rec.y = py17[2]; p169_rec.x = px5;
            Rectangle p170_rec = p17_rec; p170_rec.y = py17[3]; p170_rec.x = px5;
            Rectangle p171_rec = p18_rec; p171_rec.y = py17[4]; p171_rec.x = px5;
            Rectangle p172_rec = p19_rec; p172_rec.y = py17[5]; p172_rec.x = px5;
            Rectangle p173_rec = p20_rec; p173_rec.y = py17[6]; p173_rec.x = px5;
            Rectangle p174_rec = p21_rec; p174_rec.y = py17[7]; p174_rec.x = px5;
            Rectangle p175_rec = p22_rec; p175_rec.y = py17[8]; p175_rec.x = px5;
            Rectangle p176_rec = p23_rec; p176_rec.y = py17[9]; p176_rec.x = px5;

            Rectangle p177_rec = p14_rec; p177_rec.y = py18[0]; p177_rec.x = px4;
            Rectangle p178_rec = p15_rec; p178_rec.y = py18[1]; p178_rec.x = px4;
            Rectangle p179_rec = p16_rec; p179_rec.y = py18[2]; p179_rec.x = px4;
            Rectangle p180_rec = p17_rec; p180_rec.y = py18[3]; p180_rec.x = px4;
            Rectangle p181_rec = p18_rec; p181_rec.y = py18[4]; p181_rec.x = px4;
            Rectangle p182_rec = p19_rec; p182_rec.y = py18[5]; p182_rec.x = px4;
            Rectangle p183_rec = p20_rec; p183_rec.y = py18[6]; p183_rec.x = px4;
            Rectangle p184_rec = p21_rec; p184_rec.y = py18[7]; p184_rec.x = px4;
            Rectangle p185_rec = p22_rec; p185_rec.y = py18[8]; p185_rec.x = px4;
            Rectangle p186_rec = p23_rec; p186_rec.y = py18[9]; p186_rec.x = px4;

            Rectangle p187_rec = p14_rec; p187_rec.y = py19[0]; p187_rec.x = px4;
            Rectangle p188_rec = p15_rec; p188_rec.y = py19[1]; p188_rec.x = px4;
            Rectangle p189_rec = p16_rec; p189_rec.y = py19[2]; p189_rec.x = px4;
            Rectangle p190_rec = p17_rec; p190_rec.y = py19[3]; p190_rec.x = px4;
            Rectangle p191_rec = p18_rec; p191_rec.y = py19[4]; p191_rec.x = px4;
            Rectangle p192_rec = p19_rec; p192_rec.y = py19[5]; p192_rec.x = px4;
            Rectangle p193_rec = p20_rec; p193_rec.y = py19[6]; p193_rec.x = px4;
            Rectangle p194_rec = p21_rec; p194_rec.y = py19[7]; p194_rec.x = px4;
            Rectangle p195_rec = p22_rec; p195_rec.y = py19[8]; p195_rec.x = px4;
            Rectangle p196_rec = p23_rec; p196_rec.y = py19[9]; p196_rec.x = px4;

            Rectangle p197_rec = p14_rec; p197_rec.y = py20[0]; p197_rec.x = px5;
            Rectangle p198_rec = p15_rec; p198_rec.y = py20[1]; p198_rec.x = px5;
            Rectangle p199_rec = p16_rec; p199_rec.y = py20[2]; p199_rec.x = px5;
            Rectangle p200_rec = p17_rec; p200_rec.y = py20[3]; p200_rec.x = px5;
            Rectangle p201_rec = p18_rec; p201_rec.y = py20[4]; p201_rec.x = px5;
            Rectangle p202_rec = p19_rec; p202_rec.y = py20[5]; p202_rec.x = px5;
            Rectangle p203_rec = p20_rec; p203_rec.y = py20[6]; p203_rec.x = px5;
            Rectangle p204_rec = p21_rec; p204_rec.y = py20[7]; p204_rec.x = px5;
            Rectangle p205_rec = p22_rec; p205_rec.y = py20[8]; p205_rec.x = px5;
            Rectangle p206_rec = p23_rec; p206_rec.y = py20[9]; p206_rec.x = px5;

            Rectangle p207_rec = p14_rec; p207_rec.y = py21[0]; p207_rec.x = px4;
            Rectangle p208_rec = p15_rec; p208_rec.y = py21[1]; p208_rec.x = px4;
            Rectangle p209_rec = p16_rec; p209_rec.y = py21[2]; p209_rec.x = px4;
            Rectangle p210_rec = p17_rec; p210_rec.y = py21[3]; p210_rec.x = px4;
            Rectangle p211_rec = p18_rec; p211_rec.y = py21[4]; p211_rec.x = px4;
            Rectangle p212_rec = p19_rec; p212_rec.y = py21[5]; p212_rec.x = px4;
            Rectangle p213_rec = p20_rec; p213_rec.y = py21[6]; p213_rec.x = px4;
            Rectangle p214_rec = p21_rec; p214_rec.y = py21[7]; p214_rec.x = px4;
            Rectangle p215_rec = p22_rec; p215_rec.y = py21[8]; p215_rec.x = px4;
            Rectangle p216_rec = p23_rec; p216_rec.y = py21[9]; p216_rec.x = px4;

            Rectangle p217_rec = p14_rec; p217_rec.y = py22[0]; p217_rec.x = px5;
            Rectangle p218_rec = p15_rec; p218_rec.y = py22[1]; p218_rec.x = px5;
            Rectangle p219_rec = p16_rec; p219_rec.y = py22[2]; p219_rec.x = px5;
            Rectangle p220_rec = p17_rec; p220_rec.y = py22[3]; p220_rec.x = px5;
            Rectangle p221_rec = p18_rec; p221_rec.y = py22[4]; p221_rec.x = px5;
            Rectangle p222_rec = p19_rec; p222_rec.y = py22[5]; p222_rec.x = px5;
            Rectangle p223_rec = p20_rec; p223_rec.y = py22[6]; p223_rec.x = px5;
            Rectangle p224_rec = p21_rec; p224_rec.y = py22[7]; p224_rec.x = px5;
            Rectangle p225_rec = p22_rec; p225_rec.y = py22[8]; p225_rec.x = px5;
            Rectangle p226_rec = p23_rec; p226_rec.y = py22[9]; p226_rec.x = px5;

            Rectangle p227_rec = p14_rec; p227_rec.y = py23[0]; p227_rec.x = px6;
            Rectangle p228_rec = p15_rec; p228_rec.y = py23[1]; p228_rec.x = px6;
            Rectangle p229_rec = p16_rec; p229_rec.y = py23[2]; p229_rec.x = px6;
            Rectangle p230_rec = p17_rec; p230_rec.y = py23[3]; p230_rec.x = px6;
            Rectangle p231_rec = p18_rec; p231_rec.y = py23[4]; p231_rec.x = px6;
            Rectangle p232_rec = p19_rec; p232_rec.y = py23[5]; p232_rec.x = px6;
            Rectangle p233_rec = p20_rec; p233_rec.y = py23[6]; p233_rec.x = px6;
            Rectangle p234_rec = p21_rec; p234_rec.y = py23[7]; p234_rec.x = px6;
            Rectangle p235_rec = p22_rec; p235_rec.y = py23[8]; p235_rec.x = px6;
            Rectangle p236_rec = p23_rec; p236_rec.y = py23[9]; p236_rec.x = px6;

            Vector2 piece1_origin = {.x = 100,.y = 100,};



            //rectangle autour de la moto
            Rectangle moto_rec = {
                .x = moto_x,
                .y = moto_y,
                .width = moto_height,
                .height = moto_width,
            };

            //gestion de la mobilite des obstacles;
            float rad = PI * 1 / 180;
            float ob_y_move = 50 * sinf( rad );
            float ob_x_move = 50 * cosf( rad );



        ///AFFICHAGE L'AIRE DE JEU

        if(!VisiblePage && !Instructionpage && !raceOver){

            if(action == false){
                if( IsKeyDown( KEY_SPACE) ) {
                    pause = true;
                }
            }
            if( IsKeyDown( KEY_M) ) {
                pause = false;
            }
            int tile_count_col = ceil( world_width / soil_texture.width );
            int tile_count_row = ceil( world_height / soil_texture.height );

            for( int x = 0; x < tile_count_col; x++ ) {
                for( int y = 0;  - y < tile_count_row; y-- ) {
                    DrawTexture(soil_texture, x * soil_texture.width, y * soil_texture.height, WHITE); // affichage de la route
                }
            }

            DrawTexture(start_line_texture,  95, 350, WHITE); // affichage de la ligne de départ
            DrawTexture(end_line_texture,  95, -30000, WHITE); // affichage de la ligne d'arrivée
            DrawText("ARRIVEE", 350, -30200, 100, WHITE);
            DrawTexture(flag_texture,  450, 180, WHITE);// affichage du drapeau


            //gestion de la mobilite de la moto 1;
            if( moto_rotation >= 360 ) {
                moto_rotation = 0;
            }

            float radians = PI * moto_rotation / 180;
            float x_move = moto_speed * cosf( radians );
            float y_move = moto_speed * sinf( radians );



        /********************
            ************************************** AFFICHAGE DES OBSTACLES************************************************

            **************************************************************************************************************************************
        */

            Vector2 ob1_origin = {.x = 328/2,.y = 200/2,};
            Vector2 ob2_origin = {.x = 592/2,.y = 280/2,};
            Vector2 ob3_origin = {.x = 319/2,.y = 200/2,};


            DrawTexturePro(ob1_texture, ob1_texture_rec, ob1_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob2_texture, ob3_texture_rec, ob2_rec, ob2_origin, 0, WHITE);
            DrawTexturePro(ob3_texture, ob3_texture_rec, ob3_rec, ob2_origin, 0, WHITE);
            DrawTexturePro(ob5_texture, ob5_texture_rec, ob5_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob6_texture, ob6_texture_rec, ob6_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob7_texture, ob7_texture_rec, ob7_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob8_texture, ob8_texture_rec, ob8_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob9_texture, ob9_texture_rec, ob9_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob10_texture, ob10_texture_rec, ob10_rec, ob2_origin, 0, WHITE);
            DrawTexturePro(ob11_texture, ob11_texture_rec, ob11_rec, ob3_origin, 0, WHITE);
            DrawTexturePro(ob13_texture, ob13_texture_rec, ob13_rec, ob3_origin, 0, WHITE);
            DrawTexturePro(ob5_texture, ob5_texture_rec, ob14_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob13_texture, ob13_texture_rec, ob15_rec, ob3_origin, 0, WHITE);
            DrawTexturePro(ob1_texture, ob1_texture_rec, ob16_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob8_texture, ob8_texture_rec, ob17_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob10_texture, ob10_texture_rec, ob18_rec, ob2_origin, 0, WHITE);
            DrawTexturePro(ob4_texture, ob4_texture_rec, ob19_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob4_texture, ob4_texture_rec, ob20_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob13_texture, ob13_texture_rec, ob21_rec, ob3_origin, 0, WHITE);
            DrawTexturePro(ob1_texture, ob1_texture_rec, ob22_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob2_texture, ob3_texture_rec, ob23_rec, ob3_origin, 0, WHITE);
            DrawTexturePro(ob13_texture, ob13_texture_rec, ob24_rec, ob3_origin, 0, WHITE);
            DrawTexturePro(ob9_texture, ob9_texture_rec, ob26_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob10_texture, ob10_texture_rec, ob27_rec, ob2_origin, 0, WHITE);
            DrawTexturePro(ob1_texture, ob1_texture_rec, ob28_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob3_texture, ob3_texture_rec, ob29_rec, ob3_origin, 0, WHITE);
            DrawTexturePro(ob4_texture, ob4_texture_rec, ob30_rec, ob3_origin, 0, WHITE);
            DrawTexturePro(ob11_texture, ob11_texture_rec, ob31_rec, ob3_origin, 0, WHITE);
            DrawTexturePro(ob10_texture, ob10_texture_rec, ob32_rec, ob2_origin, 0, WHITE);
            DrawTexturePro(ob5_texture, ob5_texture_rec, ob33_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob13_texture, ob13_texture_rec, ob34_rec, ob3_origin, 0, WHITE); /////
            DrawTexturePro(ob4_texture, ob4_texture_rec, ob35_rec, ob3_origin, 0, WHITE);
            DrawTexturePro(ob2_texture, ob3_texture_rec, ob36_rec, ob2_origin, 0, WHITE);
            DrawTexturePro(ob1_texture, ob1_texture_rec, ob38_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob7_texture, ob7_texture_rec, ob39_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob8_texture, ob8_texture_rec, ob40_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob9_texture, ob9_texture_rec, ob41_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob2_texture, ob3_texture_rec, ob42_rec, ob2_origin, 0, WHITE);
            DrawTexturePro(ob6_texture, ob6_texture_rec, ob43_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob8_texture, ob8_texture_rec, ob44_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob1_texture, ob1_texture_rec, ob45_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob3_texture, ob3_texture_rec, ob46_rec, ob3_origin, 0, WHITE);
            DrawTexturePro(ob4_texture, ob4_texture_rec, ob47_rec, ob3_origin, 0, WHITE);
            DrawTexturePro(ob10_texture, ob10_texture_rec, ob48_rec, ob2_origin, 0, WHITE);
            DrawTexturePro(ob11_texture, ob11_texture_rec, ob49_rec, ob3_origin, 0, WHITE);
            DrawTexturePro(ob13_texture, ob13_texture_rec, ob50_rec, ob3_origin, 0, WHITE);
            DrawTexturePro(ob10_texture, ob10_texture_rec, ob52_rec, ob2_origin, 0, WHITE);
            DrawTexturePro(ob13_texture, ob13_texture_rec, ob53_rec, ob3_origin, 0, WHITE);
            DrawTexturePro(ob11_texture, ob11_texture_rec, ob54_rec, ob3_origin, 0, WHITE);
            DrawTexturePro(ob3_texture, ob3_texture_rec, ob55_rec, ob2_origin, 0, WHITE);
            DrawTexturePro(ob6_texture, ob6_texture_rec, ob56_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob1_texture, ob1_texture_rec, ob57_rec, ob1_origin, 0, WHITE);
            DrawTexturePro(ob2_texture, ob3_texture_rec, ob58_rec, ob2_origin, 0, WHITE);
            DrawTexturePro(ob11_texture, ob11_texture_rec, ob59_rec, ob3_origin, 0, WHITE);



        /********************
            ************************************** AFFICHAGE DES PIECES************************************************

            **************************************************************************************************************************************
        */




            if(!bonus1){DrawTexturePro(p5_texture, piece5_texture_rec, p1_rec, piece1_origin, 0, WHITE);}
            if(!bonus2){DrawTexturePro(p5_texture, piece5_texture_rec, p2_rec, piece1_origin, 0, WHITE);}
            if(!bonus3){DrawTexturePro(p5_texture, piece5_texture_rec, p3_rec, piece1_origin, 0, WHITE);}
            if(!bonus4){DrawTexturePro(p7_texture, piece7_texture_rec, p4_rec, piece1_origin, 0, WHITE);}
            if(!bonus5){DrawTexturePro(p7_texture, piece7_texture_rec, p5_rec, piece1_origin, 0, WHITE);}
            if(!bonus6){DrawTexturePro(p8_texture, piece8_texture_rec, p6_rec, piece1_origin, 0, WHITE);}
            if(!bonus7){DrawTexturePro(p8_texture, piece8_texture_rec, p7_rec, piece1_origin, 0, WHITE);}
            if(!bonus8){DrawTexturePro(p6_texture, piece6_texture_rec, p8_rec, piece1_origin, 0, WHITE);}
            if(!bonus9){DrawTexturePro(p7_texture, piece7_texture_rec, p9_rec, piece1_origin, 0, WHITE);}
            if(!bonus10){DrawTexturePro(p6_texture, piece6_texture_rec, p10_rec, piece1_origin, 0, WHITE);}//
            if(!bonus14){DrawTexturePro(p5_texture, piece5_texture_rec, p14_rec, piece1_origin, 0, WHITE);}
            if(!bonus17){DrawTexturePro(p6_texture, piece6_texture_rec, p15_rec, piece1_origin, 0, WHITE);}
            if(!bonus16){DrawTexturePro(p7_texture, piece7_texture_rec, p16_rec, piece1_origin, 0, WHITE);}
            if(!bonus17){DrawTexturePro(p8_texture, piece8_texture_rec, p17_rec, piece1_origin, 0, WHITE);}
            if(!bonus18){DrawTexturePro(p5_texture, piece5_texture_rec, p18_rec, piece1_origin, 0, WHITE);}
            if(!bonus19){DrawTexturePro(p6_texture, piece6_texture_rec, p19_rec, piece1_origin, 0, WHITE);}
            if(!bonus20){DrawTexturePro(p7_texture, piece7_texture_rec, p20_rec, piece1_origin, 0, WHITE);}
            if(!bonus21){DrawTexturePro(p8_texture, piece8_texture_rec, p21_rec, piece1_origin, 0, WHITE);}
            if(!bonus22){DrawTexturePro(p8_texture, piece8_texture_rec, p22_rec, piece1_origin, 0, WHITE);}
            if(!bonus23){DrawTexturePro(p6_texture, piece6_texture_rec, p23_rec, piece1_origin, 0, WHITE);}
            if(!bonus27){DrawTexturePro(p5_texture, piece5_texture_rec, p27_rec, piece1_origin, 0, WHITE);}
            if(!bonus28){DrawTexturePro(p5_texture, piece5_texture_rec, p28_rec, piece1_origin, 0, WHITE);}
            if(!bonus29){DrawTexturePro(p5_texture, piece5_texture_rec, p29_rec, piece1_origin, 0, WHITE);}
            if(!bonus30){DrawTexturePro(p7_texture, piece7_texture_rec, p30_rec, piece1_origin, 0, WHITE);}
            if(!bonus31){DrawTexturePro(p7_texture, piece7_texture_rec, p31_rec, piece1_origin, 0, WHITE);}
            if(!bonus32){DrawTexturePro(p8_texture, piece8_texture_rec, p32_rec, piece1_origin, 0, WHITE);}
            if(!bonus33){DrawTexturePro(p8_texture, piece8_texture_rec, p33_rec, piece1_origin, 0, WHITE);}
            if(!bonus34){DrawTexturePro(p6_texture, piece6_texture_rec, p34_rec, piece1_origin, 0, WHITE);}
            if(!bonus35){DrawTexturePro(p7_texture, piece7_texture_rec, p35_rec, piece1_origin, 0, WHITE);}
            if(!bonus36){DrawTexturePro(p6_texture, piece6_texture_rec, p36_rec, piece1_origin, 0, WHITE);}
            if(!bonus37){DrawTexturePro(p5_texture, piece5_texture_rec, p37_rec, piece1_origin, 0, WHITE);}
            if(!bonus38){DrawTexturePro(p6_texture, piece6_texture_rec, p38_rec, piece1_origin, 0, WHITE);}
            if(!bonus39){DrawTexturePro(p7_texture, piece7_texture_rec, p39_rec, piece1_origin, 0, WHITE);}
            if(!bonus40){DrawTexturePro(p8_texture, piece8_texture_rec, p40_rec, piece1_origin, 0, WHITE);}
            if(!bonus41){DrawTexturePro(p5_texture, piece5_texture_rec, p41_rec, piece1_origin, 0, WHITE);}
            if(!bonus42){DrawTexturePro(p6_texture, piece6_texture_rec, p42_rec, piece1_origin, 0, WHITE);}
            if(!bonus43){DrawTexturePro(p7_texture, piece7_texture_rec, p43_rec, piece1_origin, 0, WHITE);}
            if(!bonus44){DrawTexturePro(p8_texture, piece8_texture_rec, p44_rec, piece1_origin, 0, WHITE);}
            if(!bonus45){DrawTexturePro(p8_texture, piece8_texture_rec, p45_rec, piece1_origin, 0, WHITE);}
            if(!bonus46){DrawTexturePro(p6_texture, piece6_texture_rec, p46_rec, piece1_origin, 0, WHITE);}
            if(!bonus47){DrawTexturePro(p5_texture, piece5_texture_rec, p47_rec, piece1_origin, 0, WHITE);}
            if(!bonus48){DrawTexturePro(p6_texture, piece6_texture_rec, p48_rec, piece1_origin, 0, WHITE);}
            if(!bonus49){DrawTexturePro(p7_texture, piece7_texture_rec, p49_rec, piece1_origin, 0, WHITE);}
            if(!bonus50){DrawTexturePro(p8_texture, piece8_texture_rec, p50_rec, piece1_origin, 0, WHITE);}
            if(!bonus51){DrawTexturePro(p5_texture, piece5_texture_rec, p51_rec, piece1_origin, 0, WHITE);}
            if(!bonus52){DrawTexturePro(p6_texture, piece6_texture_rec, p52_rec, piece1_origin, 0, WHITE);}
            if(!bonus53){DrawTexturePro(p7_texture, piece7_texture_rec, p53_rec, piece1_origin, 0, WHITE);}
            if(!bonus54){DrawTexturePro(p8_texture, piece8_texture_rec, p54_rec, piece1_origin, 0, WHITE);}
            if(!bonus55){DrawTexturePro(p8_texture, piece8_texture_rec, p55_rec, piece1_origin, 0, WHITE);}
            if(!bonus56){DrawTexturePro(p6_texture, piece6_texture_rec, p56_rec, piece1_origin, 0, WHITE);}
            if(!bonus57){DrawTexturePro(p5_texture, piece5_texture_rec, p57_rec, piece1_origin, 0, WHITE);}
            if(!bonus58){DrawTexturePro(p5_texture, piece5_texture_rec, p58_rec, piece1_origin, 0, WHITE);}
            if(!bonus59){DrawTexturePro(p5_texture, piece5_texture_rec, p59_rec, piece1_origin, 0, WHITE);}
            if(!bonus60){DrawTexturePro(p5_texture, piece5_texture_rec, p60_rec, piece1_origin, 0, WHITE);}
            if(!bonus61){DrawTexturePro(p7_texture, piece7_texture_rec, p61_rec, piece1_origin, 0, WHITE);}
            if(!bonus62){DrawTexturePro(p7_texture, piece7_texture_rec, p62_rec, piece1_origin, 0, WHITE);}
            if(!bonus63){DrawTexturePro(p8_texture, piece8_texture_rec, p63_rec, piece1_origin, 0, WHITE);}
            if(!bonus64){DrawTexturePro(p8_texture, piece8_texture_rec, p64_rec, piece1_origin, 0, WHITE);}
            if(!bonus65){DrawTexturePro(p7_texture, piece7_texture_rec, p65_rec, piece1_origin, 0, WHITE);}
            if(!bonus66){DrawTexturePro(p7_texture, piece7_texture_rec, p66_rec, piece1_origin, 0, WHITE);}//
            if(!bonus67){DrawTexturePro(p5_texture, piece5_texture_rec, p67_rec, piece1_origin, 0, WHITE);}
            if(!bonus68){DrawTexturePro(p5_texture, piece5_texture_rec, p68_rec, piece1_origin, 0, WHITE);}
            if(!bonus69){DrawTexturePro(p5_texture, piece5_texture_rec, p69_rec, piece1_origin, 0, WHITE);}
            if(!bonus70){DrawTexturePro(p7_texture, piece7_texture_rec, p70_rec, piece1_origin, 0, WHITE);}
            if(!bonus71){DrawTexturePro(p7_texture, piece7_texture_rec, p71_rec, piece1_origin, 0, WHITE);}
            if(!bonus72){DrawTexturePro(p8_texture, piece8_texture_rec, p72_rec, piece1_origin, 0, WHITE);}
            if(!bonus73){DrawTexturePro(p8_texture, piece8_texture_rec, p73_rec, piece1_origin, 0, WHITE);}
            if(!bonus74){DrawTexturePro(p6_texture, piece6_texture_rec, p74_rec, piece1_origin, 0, WHITE);}
            if(!bonus75){DrawTexturePro(p7_texture, piece7_texture_rec, p75_rec, piece1_origin, 0, WHITE);}
            if(!bonus76){DrawTexturePro(p6_texture, piece6_texture_rec, p76_rec, piece1_origin, 0, WHITE);}//
            if(!bonus77){DrawTexturePro(p5_texture, piece5_texture_rec, p77_rec, piece1_origin, 0, WHITE);}
            if(!bonus78){DrawTexturePro(p6_texture, piece6_texture_rec, p78_rec, piece1_origin, 0, WHITE);}
            if(!bonus79){DrawTexturePro(p7_texture, piece7_texture_rec, p79_rec, piece1_origin, 0, WHITE);}
            if(!bonus80){DrawTexturePro(p8_texture, piece8_texture_rec, p80_rec, piece1_origin, 0, WHITE);}
            if(!bonus81){DrawTexturePro(p5_texture, piece5_texture_rec, p81_rec, piece1_origin, 0, WHITE);}
            if(!bonus82){DrawTexturePro(p6_texture, piece6_texture_rec, p82_rec, piece1_origin, 0, WHITE);}
            if(!bonus83){DrawTexturePro(p7_texture, piece7_texture_rec, p83_rec, piece1_origin, 0, WHITE);}
            if(!bonus84){DrawTexturePro(p8_texture, piece8_texture_rec, p84_rec, piece1_origin, 0, WHITE);}
            if(!bonus85){DrawTexturePro(p8_texture, piece8_texture_rec, p85_rec, piece1_origin, 0, WHITE);}
            if(!bonus86){DrawTexturePro(p6_texture, piece6_texture_rec, p86_rec, piece1_origin, 0, WHITE);}//8
            if(!bonus87){DrawTexturePro(p5_texture, piece5_texture_rec, p87_rec, piece1_origin, 0, WHITE);}
            if(!bonus88){DrawTexturePro(p5_texture, piece5_texture_rec, p88_rec, piece1_origin, 0, WHITE);}
            if(!bonus89){DrawTexturePro(p5_texture, piece5_texture_rec, p89_rec, piece1_origin, 0, WHITE);}
            if(!bonus90){DrawTexturePro(p5_texture, piece5_texture_rec, p90_rec, piece1_origin, 0, WHITE);}
            if(!bonus91){DrawTexturePro(p7_texture, piece7_texture_rec, p91_rec, piece1_origin, 0, WHITE);}
            if(!bonus92){DrawTexturePro(p7_texture, piece7_texture_rec, p92_rec, piece1_origin, 0, WHITE);}
            if(!bonus93){DrawTexturePro(p8_texture, piece8_texture_rec, p93_rec, piece1_origin, 0, WHITE);}
            if(!bonus94){DrawTexturePro(p8_texture, piece8_texture_rec, p94_rec, piece1_origin, 0, WHITE);}
            if(!bonus95){DrawTexturePro(p7_texture, piece7_texture_rec, p95_rec, piece1_origin, 0, WHITE);}
            if(!bonus96){DrawTexturePro(p7_texture, piece7_texture_rec, p96_rec, piece1_origin, 0, WHITE);}//9
            if(!bonus97){DrawTexturePro(p5_texture, piece5_texture_rec, p97_rec, piece1_origin, 0, WHITE);}
            if(!bonus98){DrawTexturePro(p6_texture, piece6_texture_rec, p98_rec, piece1_origin, 0, WHITE);}
            if(!bonus99){DrawTexturePro(p7_texture, piece7_texture_rec, p99_rec, piece1_origin, 0, WHITE);}
            if(!bonus100){DrawTexturePro(p8_texture, piece8_texture_rec, p100_rec, piece1_origin, 0, WHITE);}
            if(!bonus101){DrawTexturePro(p5_texture, piece5_texture_rec, p101_rec, piece1_origin, 0, WHITE);}
            if(!bonus102){DrawTexturePro(p6_texture, piece6_texture_rec, p102_rec, piece1_origin, 0, WHITE);}
            if(!bonus103){DrawTexturePro(p7_texture, piece7_texture_rec, p103_rec, piece1_origin, 0, WHITE);}
            if(!bonus104){DrawTexturePro(p8_texture, piece8_texture_rec, p104_rec, piece1_origin, 0, WHITE);}
            if(!bonus105){DrawTexturePro(p8_texture, piece8_texture_rec, p105_rec, piece1_origin, 0, WHITE);}
            if(!bonus106){DrawTexturePro(p6_texture, piece6_texture_rec, p106_rec, piece1_origin, 0, WHITE);}//10
            if(!bonus107){DrawTexturePro(p5_texture, piece5_texture_rec, p107_rec, piece1_origin, 0, WHITE);}
            if(!bonus108){DrawTexturePro(p5_texture, piece5_texture_rec, p108_rec, piece1_origin, 0, WHITE);}
            if(!bonus109){DrawTexturePro(p5_texture, piece5_texture_rec, p109_rec, piece1_origin, 0, WHITE);}
            if(!bonus110){DrawTexturePro(p5_texture, piece5_texture_rec, p110_rec, piece1_origin, 0, WHITE);}
            if(!bonus111){DrawTexturePro(p7_texture, piece7_texture_rec, p111_rec, piece1_origin, 0, WHITE);}
            if(!bonus112){DrawTexturePro(p7_texture, piece7_texture_rec, p112_rec, piece1_origin, 0, WHITE);}
            if(!bonus113){DrawTexturePro(p8_texture, piece8_texture_rec, p113_rec, piece1_origin, 0, WHITE);}
            if(!bonus114){DrawTexturePro(p8_texture, piece8_texture_rec, p114_rec, piece1_origin, 0, WHITE);}
            if(!bonus115){DrawTexturePro(p7_texture, piece7_texture_rec, p115_rec, piece1_origin, 0, WHITE);}
            if(!bonus116){DrawTexturePro(p7_texture, piece7_texture_rec, p116_rec, piece1_origin, 0, WHITE);}//11
            if(!bonus117){DrawTexturePro(p5_texture, piece5_texture_rec, p117_rec, piece1_origin, 0, WHITE);}
            if(!bonus118){DrawTexturePro(p6_texture, piece6_texture_rec, p118_rec, piece1_origin, 0, WHITE);}
            if(!bonus119){DrawTexturePro(p7_texture, piece7_texture_rec, p119_rec, piece1_origin, 0, WHITE);}
            if(!bonus120){DrawTexturePro(p8_texture, piece8_texture_rec, p120_rec, piece1_origin, 0, WHITE);}
            if(!bonus121){DrawTexturePro(p5_texture, piece5_texture_rec, p121_rec, piece1_origin, 0, WHITE);}
            if(!bonus122){DrawTexturePro(p6_texture, piece6_texture_rec, p122_rec, piece1_origin, 0, WHITE);}
            if(!bonus123){DrawTexturePro(p7_texture, piece7_texture_rec, p123_rec, piece1_origin, 0, WHITE);}
            if(!bonus124){DrawTexturePro(p8_texture, piece8_texture_rec, p124_rec, piece1_origin, 0, WHITE);}
            if(!bonus125){DrawTexturePro(p8_texture, piece8_texture_rec, p125_rec, piece1_origin, 0, WHITE);}
            if(!bonus126){DrawTexturePro(p6_texture, piece6_texture_rec, p126_rec, piece1_origin, 0, WHITE);}//12
            if(!bonus127){DrawTexturePro(p5_texture, piece5_texture_rec, p127_rec, piece1_origin, 0, WHITE);}
            if(!bonus128){DrawTexturePro(p6_texture, piece6_texture_rec, p128_rec, piece1_origin, 0, WHITE);}
            if(!bonus129){DrawTexturePro(p7_texture, piece7_texture_rec, p129_rec, piece1_origin, 0, WHITE);}
            if(!bonus130){DrawTexturePro(p8_texture, piece8_texture_rec, p130_rec, piece1_origin, 0, WHITE);}
            if(!bonus131){DrawTexturePro(p5_texture, piece5_texture_rec, p131_rec, piece1_origin, 0, WHITE);}
            if(!bonus132){DrawTexturePro(p6_texture, piece6_texture_rec, p132_rec, piece1_origin, 0, WHITE);}
            if(!bonus133){DrawTexturePro(p7_texture, piece7_texture_rec, p133_rec, piece1_origin, 0, WHITE);}
            if(!bonus134){DrawTexturePro(p8_texture, piece8_texture_rec, p134_rec, piece1_origin, 0, WHITE);}
            if(!bonus135){DrawTexturePro(p8_texture, piece8_texture_rec, p135_rec, piece1_origin, 0, WHITE);}
            if(!bonus136){DrawTexturePro(p6_texture, piece6_texture_rec, p136_rec, piece1_origin, 0, WHITE);}//13
            if(!bonus137){DrawTexturePro(p5_texture, piece5_texture_rec, p137_rec, piece1_origin, 0, WHITE);}
            if(!bonus138){DrawTexturePro(p6_texture, piece6_texture_rec, p138_rec, piece1_origin, 0, WHITE);}
            if(!bonus139){DrawTexturePro(p7_texture, piece7_texture_rec, p139_rec, piece1_origin, 0, WHITE);}
            if(!bonus140){DrawTexturePro(p8_texture, piece8_texture_rec, p140_rec, piece1_origin, 0, WHITE);}
            if(!bonus141){DrawTexturePro(p5_texture, piece5_texture_rec, p141_rec, piece1_origin, 0, WHITE);}
            if(!bonus142){DrawTexturePro(p6_texture, piece6_texture_rec, p142_rec, piece1_origin, 0, WHITE);}
            if(!bonus143){DrawTexturePro(p7_texture, piece7_texture_rec, p143_rec, piece1_origin, 0, WHITE);}
            if(!bonus144){DrawTexturePro(p8_texture, piece8_texture_rec, p144_rec, piece1_origin, 0, WHITE);}
            if(!bonus145){DrawTexturePro(p8_texture, piece8_texture_rec, p145_rec, piece1_origin, 0, WHITE);}
            if(!bonus146){DrawTexturePro(p6_texture, piece6_texture_rec, p146_rec, piece1_origin, 0, WHITE);}//14
            if(!bonus147){DrawTexturePro(p5_texture, piece5_texture_rec, p147_rec, piece1_origin, 0, WHITE);}
            if(!bonus148){DrawTexturePro(p6_texture, piece6_texture_rec, p148_rec, piece1_origin, 0, WHITE);}
            if(!bonus149){DrawTexturePro(p7_texture, piece7_texture_rec, p149_rec, piece1_origin, 0, WHITE);}
            if(!bonus150){DrawTexturePro(p8_texture, piece8_texture_rec, p150_rec, piece1_origin, 0, WHITE);}
            if(!bonus151){DrawTexturePro(p5_texture, piece5_texture_rec, p151_rec, piece1_origin, 0, WHITE);}
            if(!bonus152){DrawTexturePro(p6_texture, piece6_texture_rec, p152_rec, piece1_origin, 0, WHITE);}
            if(!bonus153){DrawTexturePro(p7_texture, piece7_texture_rec, p153_rec, piece1_origin, 0, WHITE);}
            if(!bonus154){DrawTexturePro(p8_texture, piece8_texture_rec, p154_rec, piece1_origin, 0, WHITE);}
            if(!bonus155){DrawTexturePro(p8_texture, piece8_texture_rec, p155_rec, piece1_origin, 0, WHITE);}
            if(!bonus156){DrawTexturePro(p6_texture, piece6_texture_rec, p156_rec, piece1_origin, 0, WHITE);}//15
            if(!bonus157){DrawTexturePro(p5_texture, piece5_texture_rec, p157_rec, piece1_origin, 0, WHITE);}
            if(!bonus158){DrawTexturePro(p6_texture, piece6_texture_rec, p158_rec, piece1_origin, 0, WHITE);}
            if(!bonus159){DrawTexturePro(p7_texture, piece7_texture_rec, p159_rec, piece1_origin, 0, WHITE);}
            if(!bonus160){DrawTexturePro(p8_texture, piece8_texture_rec, p160_rec, piece1_origin, 0, WHITE);}
            if(!bonus161){DrawTexturePro(p5_texture, piece5_texture_rec, p161_rec, piece1_origin, 0, WHITE);}
            if(!bonus162){DrawTexturePro(p6_texture, piece6_texture_rec, p162_rec, piece1_origin, 0, WHITE);}
            if(!bonus163){DrawTexturePro(p7_texture, piece7_texture_rec, p163_rec, piece1_origin, 0, WHITE);}
            if(!bonus164){DrawTexturePro(p8_texture, piece8_texture_rec, p164_rec, piece1_origin, 0, WHITE);}
            if(!bonus165){DrawTexturePro(p8_texture, piece8_texture_rec, p165_rec, piece1_origin, 0, WHITE);}
            if(!bonus166){DrawTexturePro(p6_texture, piece6_texture_rec, p166_rec, piece1_origin, 0, WHITE);}//16
            if(!bonus167){DrawTexturePro(p5_texture, piece5_texture_rec, p167_rec, piece1_origin, 0, WHITE);}
            if(!bonus168){DrawTexturePro(p6_texture, piece6_texture_rec, p168_rec, piece1_origin, 0, WHITE);}
            if(!bonus169){DrawTexturePro(p7_texture, piece7_texture_rec, p169_rec, piece1_origin, 0, WHITE);}
            if(!bonus170){DrawTexturePro(p8_texture, piece8_texture_rec, p170_rec, piece1_origin, 0, WHITE);}
            if(!bonus171){DrawTexturePro(p5_texture, piece5_texture_rec, p171_rec, piece1_origin, 0, WHITE);}
            if(!bonus172){DrawTexturePro(p6_texture, piece6_texture_rec, p172_rec, piece1_origin, 0, WHITE);}
            if(!bonus173){DrawTexturePro(p7_texture, piece7_texture_rec, p173_rec, piece1_origin, 0, WHITE);}
            if(!bonus174){DrawTexturePro(p8_texture, piece8_texture_rec, p174_rec, piece1_origin, 0, WHITE);}
            if(!bonus175){DrawTexturePro(p8_texture, piece8_texture_rec, p175_rec, piece1_origin, 0, WHITE);}
            if(!bonus176){DrawTexturePro(p6_texture, piece6_texture_rec, p176_rec, piece1_origin, 0, WHITE);}//17
            if(!bonus177){DrawTexturePro(p5_texture, piece5_texture_rec, p177_rec, piece1_origin, 0, WHITE);}
            if(!bonus178){DrawTexturePro(p6_texture, piece6_texture_rec, p178_rec, piece1_origin, 0, WHITE);}
            if(!bonus179){DrawTexturePro(p7_texture, piece7_texture_rec, p179_rec, piece1_origin, 0, WHITE);}
            if(!bonus180){DrawTexturePro(p8_texture, piece8_texture_rec, p180_rec, piece1_origin, 0, WHITE);}
            if(!bonus181){DrawTexturePro(p5_texture, piece5_texture_rec, p181_rec, piece1_origin, 0, WHITE);}
            if(!bonus182){DrawTexturePro(p6_texture, piece6_texture_rec, p182_rec, piece1_origin, 0, WHITE);}
            if(!bonus183){DrawTexturePro(p7_texture, piece7_texture_rec, p183_rec, piece1_origin, 0, WHITE);}
            if(!bonus184){DrawTexturePro(p8_texture, piece8_texture_rec, p184_rec, piece1_origin, 0, WHITE);}
            if(!bonus185){DrawTexturePro(p8_texture, piece8_texture_rec, p185_rec, piece1_origin, 0, WHITE);}
            if(!bonus186){DrawTexturePro(p6_texture, piece6_texture_rec, p186_rec, piece1_origin, 0, WHITE);}//18
            if(!bonus187){DrawTexturePro(p5_texture, piece5_texture_rec, p187_rec, piece1_origin, 0, WHITE);}
            if(!bonus188){DrawTexturePro(p6_texture, piece6_texture_rec, p188_rec, piece1_origin, 0, WHITE);}
            if(!bonus189){DrawTexturePro(p7_texture, piece7_texture_rec, p189_rec, piece1_origin, 0, WHITE);}
            if(!bonus190){DrawTexturePro(p8_texture, piece8_texture_rec, p190_rec, piece1_origin, 0, WHITE);}
            if(!bonus191){DrawTexturePro(p5_texture, piece5_texture_rec, p191_rec, piece1_origin, 0, WHITE);}
            if(!bonus192){DrawTexturePro(p6_texture, piece6_texture_rec, p192_rec, piece1_origin, 0, WHITE);}
            if(!bonus193){DrawTexturePro(p7_texture, piece7_texture_rec, p193_rec, piece1_origin, 0, WHITE);}
            if(!bonus194){DrawTexturePro(p8_texture, piece8_texture_rec, p194_rec, piece1_origin, 0, WHITE);}
            if(!bonus195){DrawTexturePro(p8_texture, piece8_texture_rec, p195_rec, piece1_origin, 0, WHITE);}
            if(!bonus196){DrawTexturePro(p6_texture, piece6_texture_rec, p196_rec, piece1_origin, 0, WHITE);}//19
            if(!bonus197){DrawTexturePro(p5_texture, piece5_texture_rec, p197_rec, piece1_origin, 0, WHITE);}
            if(!bonus198){DrawTexturePro(p6_texture, piece6_texture_rec, p198_rec, piece1_origin, 0, WHITE);}
            if(!bonus199){DrawTexturePro(p7_texture, piece7_texture_rec, p199_rec, piece1_origin, 0, WHITE);}
            if(!bonus200){DrawTexturePro(p8_texture, piece8_texture_rec, p200_rec, piece1_origin, 0, WHITE);}
            if(!bonus201){DrawTexturePro(p5_texture, piece5_texture_rec, p201_rec, piece1_origin, 0, WHITE);}
            if(!bonus202){DrawTexturePro(p6_texture, piece6_texture_rec, p202_rec, piece1_origin, 0, WHITE);}
            if(!bonus203){DrawTexturePro(p7_texture, piece7_texture_rec, p203_rec, piece1_origin, 0, WHITE);}
            if(!bonus204){DrawTexturePro(p8_texture, piece8_texture_rec, p204_rec, piece1_origin, 0, WHITE);}
            if(!bonus205){DrawTexturePro(p8_texture, piece8_texture_rec, p205_rec, piece1_origin, 0, WHITE);}
            if(!bonus206){DrawTexturePro(p6_texture, piece6_texture_rec, p206_rec, piece1_origin, 0, WHITE);}//20
            if(!bonus207){DrawTexturePro(p5_texture, piece5_texture_rec, p207_rec, piece1_origin, 0, WHITE);}
            if(!bonus208){DrawTexturePro(p6_texture, piece6_texture_rec, p208_rec, piece1_origin, 0, WHITE);}
            if(!bonus209){DrawTexturePro(p7_texture, piece7_texture_rec, p209_rec, piece1_origin, 0, WHITE);}
            if(!bonus210){DrawTexturePro(p8_texture, piece8_texture_rec, p210_rec, piece1_origin, 0, WHITE);}
            if(!bonus211){DrawTexturePro(p5_texture, piece5_texture_rec, p211_rec, piece1_origin, 0, WHITE);}
            if(!bonus212){DrawTexturePro(p6_texture, piece6_texture_rec, p212_rec, piece1_origin, 0, WHITE);}
            if(!bonus213){DrawTexturePro(p7_texture, piece7_texture_rec, p213_rec, piece1_origin, 0, WHITE);}
            if(!bonus214){DrawTexturePro(p8_texture, piece8_texture_rec, p214_rec, piece1_origin, 0, WHITE);}
            if(!bonus215){DrawTexturePro(p8_texture, piece8_texture_rec, p215_rec, piece1_origin, 0, WHITE);}
            if(!bonus216){DrawTexturePro(p6_texture, piece6_texture_rec, p216_rec, piece1_origin, 0, WHITE);}//21
            if(!bonus217){DrawTexturePro(p5_texture, piece5_texture_rec, p217_rec, piece1_origin, 0, WHITE);}
            if(!bonus218){DrawTexturePro(p6_texture, piece6_texture_rec, p218_rec, piece1_origin, 0, WHITE);}
            if(!bonus219){DrawTexturePro(p7_texture, piece7_texture_rec, p219_rec, piece1_origin, 0, WHITE);}
            if(!bonus220){DrawTexturePro(p8_texture, piece8_texture_rec, p220_rec, piece1_origin, 0, WHITE);}
            if(!bonus221){DrawTexturePro(p5_texture, piece5_texture_rec, p221_rec, piece1_origin, 0, WHITE);}
            if(!bonus222){DrawTexturePro(p6_texture, piece6_texture_rec, p222_rec, piece1_origin, 0, WHITE);}
            if(!bonus223){DrawTexturePro(p7_texture, piece7_texture_rec, p223_rec, piece1_origin, 0, WHITE);}
            if(!bonus224){DrawTexturePro(p8_texture, piece8_texture_rec, p224_rec, piece1_origin, 0, WHITE);}
            if(!bonus225){DrawTexturePro(p8_texture, piece8_texture_rec, p225_rec, piece1_origin, 0, WHITE);}
            if(!bonus226){DrawTexturePro(p6_texture, piece6_texture_rec, p226_rec, piece1_origin, 0, WHITE);}//22
            if(!bonus227){DrawTexturePro(p5_texture, piece5_texture_rec, p227_rec, piece1_origin, 0, WHITE);}
            if(!bonus228){DrawTexturePro(p6_texture, piece6_texture_rec, p228_rec, piece1_origin, 0, WHITE);}
            if(!bonus229){DrawTexturePro(p7_texture, piece7_texture_rec, p229_rec, piece1_origin, 0, WHITE);}
            if(!bonus230){DrawTexturePro(p8_texture, piece8_texture_rec, p230_rec, piece1_origin, 0, WHITE);}
            if(!bonus231){DrawTexturePro(p5_texture, piece5_texture_rec, p231_rec, piece1_origin, 0, WHITE);}
            if(!bonus232){DrawTexturePro(p6_texture, piece6_texture_rec, p232_rec, piece1_origin, 0, WHITE);}
            if(!bonus233){DrawTexturePro(p7_texture, piece7_texture_rec, p233_rec, piece1_origin, 0, WHITE);}
            if(!bonus234){DrawTexturePro(p8_texture, piece8_texture_rec, p234_rec, piece1_origin, 0, WHITE);}
            if(!bonus235){DrawTexturePro(p8_texture, piece8_texture_rec, p235_rec, piece1_origin, 0, WHITE);}
            if(!bonus236){DrawTexturePro(p6_texture, piece6_texture_rec, p236_rec, piece1_origin, 0, WHITE);}//23




            ///EMPECHER LA PREMIERE MOTO DE QUITTER LA ROUTE

            if(moto_x >= 950){
                moto_x = 950 ;
            } else if(moto_x <= 200) {
                moto_x = 200;
            }

            if(moto_y >= 750){
                moto_y = 750;
            }



            ///DEPLACEMENT DE LA CAMERA

            // Calcule le décalage de la caméra sur la position de la moto
            camera.offset.y = -8700;

            // Définir la cible de la caméra sur la position du la moto avec le décalage
            camera.target.y =  moto_y + camera.offset.y;


            ///Affichage de la moto

            Vector2 moto_origin = {
                .x = moto_height/2,
                .y = moto_width/2,
            };


            DrawTexturePro(moto_texture, moto_texture_rec, moto_rec, moto_origin, moto_rotation, WHITE);

            ///ARRET DE LA MOTO  APRES TRAVERSEE DE LA LIGNE D'ARRIVEE

            if(moto_y <= -30200){
                moto_y = -30200;
            }


            ///REGLAGE DU COMPTE A REBOURS
            if(controlcpt){
                UpdateMusicStream(countDown);
                PlayMusicStream(countDown);
                // Affichage du compte à rebours
                if(cpt != 0){
                    DrawText(TextFormat("%d", cpt), 500, 0, 280, YELLOW);
                }
                if(cpt == 0){
                    DrawText("GO!", 415, 0, 180, YELLOW);
                }
                // Mise à jour du compte à rebours
                elapsedTime += dt;

                if(!pause){
                    if (elapsedTime >= 1) {
                        cpt--;
                        elapsedTime = 0;
                    }

                } else {
                    PauseMusicStream(countDown);
                    UpdateMusicStream(music);
                    PlayMusicStream(music);
                    if (elapsedTime >= 1) {
                        cpt +=0;
                        elapsedTime = 0;
                    }
                }

            }

/***
    *********************************************DEBUT DE LA COURSE APRES LA FIN DU COMPTE A REBOURS************************************
    ************************************************************************************************************************************
*/

            if(cpt == -1){
                controlcpt = false;
                PauseMusicStream(music);
                UpdateMusicStream(songMoto);
                PlayMusicStream(songMoto);


                if(!pause){
                    /**
                *********************************** DEPLACEMENT AUTOMATIQUE DES OBSTACLES*************************************************
                **************************************************************************************************************************
            */

                y1 += ob_y_move; y2 += ob_y_move; y3 += ob_y_move; y4 += ob_y_move; y5 += ob_y_move; y7 += ob_y_move; y8 += ob_y_move; y9 += ob_y_move;
                y10 += ob_y_move; y11 += ob_y_move; y12 += ob_y_move; y13 += ob_y_move; y14 += ob_y_move; y15 += ob_y_move; y16 += ob_y_move; y17 += ob_y_move; y18 += ob_y_move;
                y19 += ob_y_move; y20 += ob_y_move; y21 += ob_y_move; y22 += ob_y_move; y23 += ob_y_move; y24 += ob_y_move; y25 += ob_y_move; y26 += ob_y_move; y27 += ob_y_move;
                y28 += ob_y_move; y29 += ob_y_move; y30 += ob_y_move; y31 += ob_y_move; y32 += ob_y_move; y33 += ob_y_move; y34 += ob_y_move; y35 += ob_y_move;
                y36 += ob_y_move; y37 += ob_y_move; y38 += ob_y_move, y39 += ob_y_move; y42 += ob_y_move; y43 += ob_y_move; y44 += ob_y_move; y45 += ob_y_move; y46 += ob_y_move;




            /**
              *
              ************************************************CONFIGURATION DE LA PREMIERE MOTO *******************************************************
              ****************************************************************************************************************************************
            */

                if( IsKeyDown( KEY_UP ) ) {
                    moto_direction = -1;
                    moto_speed += moto_speedup * dt;
                    if( moto_speed > moto_max_speed ) {
                        moto_speed = moto_max_speed;
                    }
                    move = true;

                } else if( IsKeyDown( KEY_DOWN ) ) {
                    moto_direction = 1;
                    moto_speed -= moto_speedup * dt;
                    if( moto_speed > moto_max_speed ) {
                        moto_speed = moto_max_speed;
                    }
                    move = true;
                } else {
                    moto_speed += moto_slowdown * dt * moto_direction;
                    if( moto_direction == -1 && moto_speed < 0 ) {
                        moto_speed = 0;
                    } else if( moto_direction == 1 && moto_speed > 0 ) {
                        moto_speed = 0;
                    }
                }

                if( IsKeyDown( KEY_LEFT ) ) {
                    moto_rotation -= ROTATION_SPEED * dt * abs( moto_speed );
                    move = true;
                } else if( IsKeyDown( KEY_RIGHT ) ) {
                    moto_rotation += ROTATION_SPEED * dt * abs( moto_speed );
                    move = true;
                }

                moto_x += x_move;
                moto_y += y_move * 2;
                } else {

                    PauseMusicStream(songMoto);
                    UpdateMusicStream(music);
                    PlayMusicStream(music);
                    y1 += 0; y2 += 0; y3 += 0; y4 += 0; y5 += 0; y7 += 0; y8 += 0; y9 += 0;
                    y10 += 0; y11 += 0; y12 += 0; y13 += 0; y14 += 0; y15 += 0; y16 += 0; y17 += 0; y18 += 0;
                    y19 += 0; y20 += 0; y21 += 0; y22 += 0; y23 += 0; y24 += 0; y25 += 0; y26 += 0; y27 += 0;
                    y28 += 0; y29 += 0; y30 += 0; y31 += 0; y32 += 0; y33 += 0; y34 += 0; y35 += 0;
                    y36 += 0; y37 += 0; y38 += 0, y39 += 0; y42 += 0; y43 += 0; y44 += 0; y45 += 0; y46 += 0;

                }





/**
*******************************************CHRONOMETRE***************************************************
 **************************************************************************************************
*/

            BeginMode2D(camera2);
            if(pause){
                DrawRectangle(GetScreenWidth() / 4, GetScreenHeight() /2.5, 450, 100, DARKGREEN);
                DrawText("PAUSED", GetScreenWidth() / 3.8, GetScreenHeight() /2.5, 100, WHITE);
            }
            if(!raceOver && !collision){
                DrawRectangle(0, 0, 300,50, DARKGREEN);
                if(s >= 10){
                    if(mn >= 10){
                        DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), 5, 5, 35, WHITE);
                    }
                    else {
                        DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), 5, 5, 35, WHITE);
                    }
                }
                if(s < 10){
                    if(mn < 10){
                        DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), 5, 5, 35, WHITE);
                    }
                    else {
                        DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), 5, 5, 35, WHITE);
                    }
                }

                // Mise à jour du compte à rebours
                time += dt;

                if(!pause){
                    if (time >= 1) {
                        s++;
                        if(s == 60){
                            s = 0;
                            mn+=1;
                        }
                        if(mn == 60){
                            mn = 0;
                            h+= 1;
                        }
                        time = 0;

                    }

                } else {
                    s+=0;

                }
            }

            //affichage du score
            DrawRectangle(950, 0, 250, 50, DARKGREEN);
            DrawText(TextFormat("Points: %d", score), 955, 5, 35, WHITE);
            EndMode2D();


            }


        }

       /**
                ***************************************GESTION DES COLLISIONS ENTRE LA MOTO ET LES PIECES**************************
                ***********************************************************************************************************************
        */

            if(CheckCollisionRecs(moto_rec, p1_rec) && !bonus1){bonus1 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p2_rec) && !bonus2){bonus2 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p3_rec) && !bonus3){bonus3 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p4_rec) && !bonus4){bonus4 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p5_rec) && !bonus5){bonus5 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p6_rec) && !bonus6){bonus6 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p7_rec) && !bonus7){bonus7 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p8_rec) && !bonus8){bonus8 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p9_rec) && !bonus9){bonus9 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p10_rec) && !bonus10){bonus10 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p14_rec) && !bonus14){bonus14 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p15_rec) && !bonus15){bonus15 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p16_rec) && !bonus16){bonus16 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p17_rec) && !bonus17){bonus17 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p18_rec) && !bonus18){bonus18 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p19_rec) && !bonus19){bonus19 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p20_rec) && !bonus20){bonus20 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p21_rec) && !bonus21){bonus21 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p22_rec) && !bonus22){bonus22 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p23_rec) && !bonus23){bonus23 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p27_rec) && !bonus7){bonus27 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p28_rec) && !bonus28){bonus28 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p29_rec) && !bonus29){bonus29 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p30_rec) && !bonus30){bonus30 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p31_rec) && !bonus31){bonus31 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p32_rec) && !bonus32){bonus32 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p33_rec) && !bonus33){bonus33 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p34_rec) && !bonus34){bonus34 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p35_rec) && !bonus35){bonus35 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p36_rec) && !bonus36){bonus36 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p37_rec) && !bonus37){bonus37 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p38_rec) && !bonus38){bonus38 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p39_rec) && !bonus39){bonus39 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p40_rec) && !bonus40){bonus40 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p41_rec) && !bonus41){bonus41 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p42_rec) && !bonus42){bonus42 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p43_rec) && !bonus43){bonus43 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p44_rec) && !bonus44){bonus44 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p45_rec) && !bonus45){bonus45 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p46_rec) && !bonus46){bonus46 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p47_rec) && !bonus47){bonus47 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p48_rec) && !bonus48){bonus48 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p49_rec) && !bonus49){bonus49 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p50_rec) && !bonus50){bonus50 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p51_rec) && !bonus51){bonus51 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p52_rec) && !bonus52){bonus52 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p53_rec) && !bonus53){bonus53 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p54_rec) && !bonus54){bonus54 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p55_rec) && !bonus55){bonus55 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p56_rec) && !bonus56){bonus56 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p57_rec) && !bonus57){bonus57 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p58_rec) && !bonus58){bonus58 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p59_rec) && !bonus59){bonus59 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p60_rec) && !bonus60){bonus60 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p61_rec) && !bonus61){bonus61 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p62_rec) && !bonus62){bonus62 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p63_rec) && !bonus63){bonus63 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p64_rec) && !bonus64){bonus64 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p65_rec) && !bonus65){bonus65 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p66_rec) && !bonus66){bonus66 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p67_rec) && !bonus67){bonus67 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p68_rec) && !bonus68){bonus68 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p69_rec) && !bonus69){bonus69 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p70_rec) && !bonus70){bonus70 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p71_rec) && !bonus71){bonus71 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p72_rec) && !bonus72){bonus72 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p73_rec) && !bonus73){bonus73 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p74_rec) && !bonus74){bonus74 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p75_rec) && !bonus75){bonus75 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p76_rec) && !bonus76){bonus76 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p77_rec) && !bonus77){bonus77 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p78_rec) && !bonus78){bonus78 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p79_rec) && !bonus79){bonus79 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p80_rec) && !bonus80){bonus80 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p81_rec) && !bonus81){bonus81 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p82_rec) && !bonus82){bonus82 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p83_rec) && !bonus83){bonus83 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p84_rec) && !bonus84){bonus84 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p85_rec) && !bonus85){bonus85 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p86_rec) && !bonus86){bonus86 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p87_rec) && !bonus87){bonus87 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p88_rec) && !bonus88){bonus88 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p89_rec) && !bonus89){bonus89 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p90_rec) && !bonus90){bonus90 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p91_rec) && !bonus91){bonus91 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p92_rec) && !bonus92){bonus92 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p93_rec) && !bonus93){bonus93 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p94_rec) && !bonus94){bonus94 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p95_rec) && !bonus95){bonus95 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p96_rec) && !bonus96){bonus96 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p97_rec) && !bonus97){bonus97 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p98_rec) && !bonus98){bonus98 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p99_rec) && !bonus99){bonus99 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p100_rec) && !bonus100){bonus100 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p101_rec) && !bonus101){bonus101 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p102_rec) && !bonus102){bonus102 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p103_rec) && !bonus103){bonus103 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p104_rec) && !bonus104){bonus104 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p105_rec) && !bonus105){bonus105 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p106_rec) && !bonus106){bonus106 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p107_rec) && !bonus107){bonus107 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p108_rec) && !bonus108){bonus108 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p109_rec) && !bonus109){bonus109 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p110_rec) && !bonus110){bonus110 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p111_rec) && !bonus111){bonus111 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p112_rec) && !bonus112){bonus112 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p113_rec) && !bonus113){bonus113 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p114_rec) && !bonus114){bonus114 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p115_rec) && !bonus115){bonus115 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p116_rec) && !bonus116){bonus116 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p117_rec) && !bonus117){bonus117 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p118_rec) && !bonus118){bonus118 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p119_rec) && !bonus119){bonus119 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p120_rec) && !bonus120){bonus120 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p121_rec) && !bonus121){bonus121 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p122_rec) && !bonus122){bonus122 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p123_rec) && !bonus123){bonus123 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p124_rec) && !bonus124){bonus124 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p125_rec) && !bonus125){bonus125 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p126_rec) && !bonus126){bonus126 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p127_rec) && !bonus127){bonus127 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p128_rec) && !bonus128){bonus128 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p129_rec) && !bonus129){bonus129 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p130_rec) && !bonus130){bonus130 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p131_rec) && !bonus131){bonus131 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p132_rec) && !bonus132){bonus132 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p133_rec) && !bonus133){bonus133 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p134_rec) && !bonus134){bonus134 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p135_rec) && !bonus135){bonus135 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p136_rec) && !bonus136){bonus136 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p137_rec) && !bonus137){bonus137 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p138_rec) && !bonus138){bonus138 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p139_rec) && !bonus139){bonus139 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p140_rec) && !bonus140){bonus140 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p141_rec) && !bonus141){bonus141 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p142_rec) && !bonus142){bonus142 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p143_rec) && !bonus143){bonus143 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p144_rec) && !bonus144){bonus144 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p145_rec) && !bonus145){bonus145 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p146_rec) && !bonus146){bonus146 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p147_rec) && !bonus147){bonus147 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p148_rec) && !bonus148){bonus148 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p149_rec) && !bonus149){bonus149 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p150_rec) && !bonus150){bonus150 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p151_rec) && !bonus151){bonus151 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p152_rec) && !bonus152){bonus152 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p153_rec) && !bonus153){bonus153 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p154_rec) && !bonus154){bonus154 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p155_rec) && !bonus155){bonus155 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p156_rec) && !bonus156){bonus156 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p157_rec) && !bonus157){bonus157 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p158_rec) && !bonus158){bonus158 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p159_rec) && !bonus159){bonus159 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p160_rec) && !bonus160){bonus160 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p161_rec) && !bonus161){bonus161 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p162_rec) && !bonus162){bonus162 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p163_rec) && !bonus163){bonus163 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p164_rec) && !bonus164){bonus164 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p165_rec) && !bonus165){bonus165 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p166_rec) && !bonus166){bonus166 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p167_rec) && !bonus167){bonus167 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p168_rec) && !bonus168){bonus168 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p169_rec) && !bonus169){bonus169 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p170_rec) && !bonus170){bonus170 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p171_rec) && !bonus171){bonus171 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p172_rec) && !bonus172){bonus172 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p173_rec) && !bonus173){bonus173 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p174_rec) && !bonus174){bonus174 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p175_rec) && !bonus175){bonus175 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p176_rec) && !bonus176){bonus176 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p177_rec) && !bonus177){bonus177 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p178_rec) && !bonus178){bonus178 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p179_rec) && !bonus179){bonus179 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p180_rec) && !bonus180){bonus180 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p181_rec) && !bonus181){bonus181 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p182_rec) && !bonus182){bonus182 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p183_rec) && !bonus183){bonus183= true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p184_rec) && !bonus184){bonus184 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p185_rec) && !bonus185){bonus185 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p186_rec) && !bonus186){bonus186 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p187_rec) && !bonus187){bonus187 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p188_rec) && !bonus188){bonus188 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p189_rec) && !bonus189){bonus189 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p190_rec) && !bonus190){bonus190 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p191_rec) && !bonus191){bonus191 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p192_rec) && !bonus192){bonus192 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p193_rec) && !bonus193){bonus193 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p194_rec) && !bonus194){bonus194 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p195_rec) && !bonus195){bonus195 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p196_rec) && !bonus196){bonus196 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p197_rec) && !bonus197){bonus197 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p198_rec) && !bonus198){bonus198 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p199_rec) && !bonus199){bonus199 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p200_rec) && !bonus200){bonus200 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p201_rec) && !bonus201){bonus201 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p202_rec) && !bonus202){bonus202 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p203_rec) && !bonus203){bonus203 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p204_rec) && !bonus204){bonus204 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p205_rec) && !bonus205){bonus205 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p206_rec) && !bonus206){bonus206 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p207_rec) && !bonus207){bonus207 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p208_rec) && !bonus208){bonus208 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p209_rec) && !bonus209){bonus209 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p210_rec) && !bonus210){bonus210 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p211_rec) && !bonus211){bonus211 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p212_rec) && !bonus212){bonus212 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p213_rec) && !bonus213){bonus213 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p214_rec) && !bonus214){bonus214 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p215_rec) && !bonus215){bonus215 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p216_rec) && !bonus216){bonus216 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p217_rec) && !bonus217){bonus217 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p218_rec) && !bonus218){bonus218 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p219_rec) && !bonus219){bonus219 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p220_rec) && !bonus220){bonus220 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p221_rec) && !bonus221){bonus221 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p222_rec) && !bonus222){bonus222 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p223_rec) && !bonus223){bonus223 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p224_rec) && !bonus224){bonus224 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p225_rec) && !bonus225){bonus225 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p226_rec) && !bonus226){bonus226 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p227_rec) && !bonus227){bonus227 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p228_rec) && !bonus228){bonus228 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p229_rec) && !bonus229){bonus229 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p230_rec) && !bonus230){bonus230 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p231_rec) && !bonus231){bonus231 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p232_rec) && !bonus232){bonus232 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p233_rec) && !bonus233){bonus233 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p234_rec) && !bonus234){bonus234 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p235_rec) && !bonus235){bonus235 = true; score += 1;}
            if(CheckCollisionRecs(moto_rec, p236_rec) && !bonus236){bonus236 = true; score += 1;}







        /**
                ***************************************GESTION DES COLLISIONS ENTRE LA MOTO ET LES OBSTACLES**************************
                ***********************************************************************************************************************
        */

        if(move == true){

            Rectangle motoprime_rec  = moto_rec; motoprime_rec.width = 2; motoprime_rec.height = 190;

            Rectangle ob1prime_rec = ob1_rec; ob1prime_rec.width = 8; ob1prime_rec.height = 328;
            if(CheckCollisionRecs(moto_rec, ob1prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {CloseWindow();}

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y1 -= ob_y_move;
                action = true;
            }
            Rectangle ob2prime_rec = ob2_rec; ob2prime_rec.width = 10; ob2prime_rec.height = 490;
            if(CheckCollisionRecs(moto_rec, ob2prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y2 -= ob_y_move;
                action = true;

            }

            Rectangle ob3prime_rec = ob3_rec; ob3prime_rec.width = 10; ob3prime_rec.height = 520;
            if(CheckCollisionRecs(moto_rec, ob3prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);
                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y3 -= ob_y_move;
                action = true;
            }
            Rectangle ob5prime_rec = ob5_rec; ob5prime_rec.width = 10; ob5prime_rec.height = 320;
            if(CheckCollisionRecs(moto_rec, ob5prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y4 -= ob_y_move;
                action = true;
            }
            Rectangle ob6prime_rec = ob6_rec; ob6prime_rec.width = 100; ob6prime_rec.height = 340;
            if(CheckCollisionRecs(moto_rec, ob6prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y5 -= ob_y_move;
                action = true;
            }
            Rectangle ob7prime_rec = ob7_rec; ob7prime_rec.width = 100; ob7prime_rec.height = 367;
            if(CheckCollisionRecs(moto_rec, ob7prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y7 -= ob_y_move;
                action = true;
            }
            Rectangle ob8prime_rec = ob8_rec; ob8prime_rec.width = 100; ob8prime_rec.height = 350;
            if(CheckCollisionRecs(moto_rec, ob8prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y7 -= ob_y_move;
                action = true;
            }
            Rectangle ob9prime_rec = ob9_rec; ob9prime_rec.width = 125; ob9prime_rec.height = 520;
            if(CheckCollisionRecs(moto_rec, ob9prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y8 -= ob_y_move;
                action = true;
            }
            Rectangle ob10prime_rec = ob10_rec; ob10prime_rec.width = 10; ob10prime_rec.height = 520;
            if(CheckCollisionRecs(moto_rec, ob10prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y9 -= ob_y_move;
                action = true;
            }
            Rectangle ob11prime_rec = ob11_rec; ob11prime_rec.width = 80; ob11prime_rec.height = 740;
            if(CheckCollisionRecs(moto_rec, ob10prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y10 -= ob_y_move;
                action = true;
            }
            Rectangle ob13prime_rec = ob13_rec; ob13prime_rec.width = 10; ob13prime_rec.height = 520;
            if(CheckCollisionRecs(moto_rec, ob13prime_rec)){
                    PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y12 -= ob_y_move;
                action = true;
            }
            Rectangle ob14prime_rec = ob14_rec; ob14prime_rec.width = 100; ob14prime_rec.height = 360;
            if(CheckCollisionRecs(moto_rec, ob14prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y12 -= ob_y_move;
                action = true;
            }
            Rectangle ob15prime_rec = ob15_rec; ob15prime_rec.width = 130; ob15prime_rec.height = 520;
            if(CheckCollisionRecs(motoprime_rec, ob15prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y13 -= ob_y_move;
                action = true;
            }
            Rectangle ob16prime_rec = ob16_rec; ob16prime_rec.width = 10; ob16prime_rec.height = 328;
            if(CheckCollisionRecs(moto_rec, ob16prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y14 -= ob_y_move;
                action = true;
            }
            Rectangle ob17prime_rec = ob17_rec; ob17prime_rec.width = 100; ob17prime_rec.height = 350;
            if(CheckCollisionRecs(moto_rec, ob17prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y15 -= ob_y_move;
                action = true;
            }
            Rectangle ob18prime_rec = ob18_rec; ob18prime_rec.width = 10; ob18prime_rec.height = 730;
            if(CheckCollisionRecs(motoprime_rec, ob18prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y16 -= ob_y_move;
                action = true;
            }
            Rectangle ob19prime_rec = ob19_rec; ob19prime_rec.width = 50; ob19prime_rec.height = 320;
            if(CheckCollisionRecs(moto_rec, ob19prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y17 -= ob_y_move;
                action = true;
            }
            Rectangle ob20prime_rec = ob20_rec; ob20prime_rec.width = 200; ob20prime_rec.height = 328;
            if(CheckCollisionRecs(moto_rec, ob20prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y18 -= ob_y_move;
                action = true;
            }
            Rectangle ob21prime_rec = ob21_rec; ob21prime_rec.width = 200; ob21prime_rec.height = 520;
            if(CheckCollisionRecs(moto_rec, ob21prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y19 -= ob_y_move;
                action = true;
            }
            Rectangle ob22prime_rec = ob22_rec; ob22prime_rec.width = 80; ob22prime_rec.height = 328;
            if(CheckCollisionRecs(moto_rec, ob22prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y20 -= ob_y_move;
                action = true;
            }
            Rectangle ob23prime_rec = ob23_rec; ob23prime_rec.width = 130; ob23prime_rec.height = 550;
            if(CheckCollisionRecs(moto_rec, ob23prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y21 -= ob_y_move;
                action = true;
            }
            Rectangle ob24prime_rec = ob24_rec; ob24prime_rec.width = 130; ob24prime_rec.height = 550;
            if(CheckCollisionRecs(moto_rec, ob24prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y22 -= ob_y_move;
                action = true;
            }
            Rectangle ob26prime_rec = ob26_rec; ob26prime_rec.width = 120; ob26prime_rec.height = 592;
            if(CheckCollisionRecs(moto_rec, ob26prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y24 -= ob_y_move;
                action = true;
            }
            Rectangle ob27prime_rec = ob27_rec; ob27prime_rec.width = 160; ob27prime_rec.height = 550; ob27prime_rec.x = ob27_rec.x-150;
            if(CheckCollisionRecs(motoprime_rec, ob27prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText("SORRY!!!", GetScreenWidth() / 2.9, GetScreenHeight() / 6 , 80, WHITE);
                DrawText("You loosed", GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y25 -= ob_y_move;
                action = true;
            }
            Rectangle ob28prime_rec = ob28_rec; ob28prime_rec.width = 50; ob28prime_rec.height = 328;
            if(CheckCollisionRecs(moto_rec, ob28prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y26 -= ob_y_move;
                action = true;
            }
            Rectangle ob29prime_rec = ob29_rec; ob29prime_rec.width = 100; ob29prime_rec.height = 550; ob29prime_rec.x = ob29_rec.x+30;
            if(CheckCollisionRecs(moto_rec, ob29prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y27 -= ob_y_move;
                action = true;
            }
            Rectangle ob30prime_rec = ob30_rec; ob30prime_rec.width = 70; ob30prime_rec.height = 320;
            if(CheckCollisionRecs(moto_rec, ob30prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y28 -= ob_y_move;
                action = true;
            }
            Rectangle ob31prime_rec = ob31_rec; ob31prime_rec.width = 90; ob31prime_rec.height = 750;
            if(CheckCollisionRecs(moto_rec, ob31prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y29 -= ob_y_move;
                action = true;
            }
            Rectangle ob32prime_rec = ob32_rec; ob32prime_rec.width = 155; ob32prime_rec.height = 550; ob32prime_rec.x = ob32_rec.x-150;
            if(CheckCollisionRecs(motoprime_rec, ob32prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y30 -= ob_y_move;
                action = true;
            }
            Rectangle ob33prime_rec = ob33_rec; ob33prime_rec.width = 110; ob33prime_rec.height = 350;
            if(CheckCollisionRecs(motoprime_rec, ob33prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y31 -= ob_y_move;
                action = true;
            }
            Rectangle ob34prime_rec = ob34_rec; ob34prime_rec.width = 90; ob34prime_rec.height = 520; ob33prime_rec.x = ob33_rec.x+30;
            if(CheckCollisionRecs(moto_rec, ob34prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y1 -= ob_y_move;
                action = true;
            }
            Rectangle ob35prime_rec = ob35_rec; ob35prime_rec.width = 90; ob35prime_rec.height = 320;
            if(CheckCollisionRecs(moto_rec, ob35prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText("SORRY!!!", GetScreenWidth() / 2.9, GetScreenHeight() / 6 , 80, WHITE);
                DrawText("You loosed", GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y32 -= ob_y_move;
                action = true;

            }
            Rectangle ob36prime_rec = ob36_rec; ob36prime_rec.width = 90; ob36prime_rec.height = 520; ob36prime_rec.x = ob36_rec.x-75;
            if(CheckCollisionRecs(moto_rec, ob36prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y3 -= ob_y_move;
                action = true;
            }
            Rectangle ob38prime_rec = ob38_rec; ob38prime_rec.width = 90; ob38prime_rec.height = 360;
            if(CheckCollisionRecs(moto_rec, ob38prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y4 -= ob_y_move;
                action = true;
            }
            Rectangle ob39prime_rec = ob39_rec; ob39prime_rec.width = 90; ob39prime_rec.height = 360; ob39prime_rec.x = ob39_rec.x+30;
            if(CheckCollisionRecs(moto_rec, ob39prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y5 -= ob_y_move;
                action = true;
            }
            Rectangle ob40prime_rec = ob40_rec; ob40prime_rec.width = 90; ob40prime_rec.height = 360; ob40prime_rec.x = ob40_rec.x+30;
            if(CheckCollisionRecs(moto_rec, ob40prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y34 -= ob_y_move;
                action = true;
            }
            Rectangle ob41prime_rec = ob41_rec; ob41prime_rec.width = 90; ob41prime_rec.height = 580; ob41prime_rec.x = ob41_rec.x-170;
            if(CheckCollisionRecs(motoprime_rec, ob41prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y8 -= ob_y_move;
                action = true;
            }
            Rectangle ob42prime_rec = ob42_rec; ob42prime_rec.width = 150; ob42prime_rec.height = 500; ob42prime_rec.x = ob42_rec.x-130;
            if(CheckCollisionRecs(moto_rec, ob42prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y35 -= ob_y_move;
                action = true;
            }
            Rectangle ob43prime_rec = ob43_rec; ob43prime_rec.width = 150; ob43prime_rec.height = 340;
            if(CheckCollisionRecs(moto_rec, ob43prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y36 -= ob_y_move;
                action = true;
            }
            Rectangle ob44prime_rec = ob44_rec; ob44prime_rec.width = 100; ob44prime_rec.height = 350;
            if(CheckCollisionRecs(moto_rec, ob44prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y11 -= ob_y_move;
                action = true;
            }
            Rectangle ob45prime_rec = ob45_rec; ob45prime_rec.width = 90; ob45prime_rec.height = 310;
            if(CheckCollisionRecs(moto_rec, ob45prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText("SORRY!!!", GetScreenWidth() / 2.9, GetScreenHeight() / 6 , 80, WHITE);
                DrawText("You loosed", GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y12 -= ob_y_move;
                action = true;
            }
            Rectangle ob46prime_rec = ob46_rec; ob46prime_rec.width = 150; ob46prime_rec.height = 575;
            if(CheckCollisionRecs(moto_rec, ob46prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y37 -= ob_y_move;
                action = true;
            }
            Rectangle ob47prime_rec = ob47_rec; ob47prime_rec.width = 150; ob47prime_rec.height = 335;
            if(CheckCollisionRecs(moto_rec, ob47prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y16 -= ob_y_move;
                action = true;
            }
            Rectangle ob48prime_rec = ob48_rec; ob48prime_rec.width = 130; ob48prime_rec.height = 570; ob48prime_rec.x = ob48_rec.x-130;
            if(CheckCollisionRecs(motoprime_rec, ob48prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y18 -= ob_y_move;
                action = true;
            }
            Rectangle ob49prime_rec = ob49_rec; ob49prime_rec.width = 90; ob49prime_rec.height = 750;
            if(CheckCollisionRecs(moto_rec, ob49prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y38 -= ob_y_move;
                action = true;
            }
            Rectangle ob50prime_rec = ob50_rec; ob50prime_rec.width = 100; ob50prime_rec.height = 500;
            if(CheckCollisionRecs(moto_rec, ob50prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y21 -= ob_y_move;
                action = true;
            }
            Rectangle ob52prime_rec = ob52_rec; ob52prime_rec.width = 100; ob52prime_rec.height = 535;
            if(CheckCollisionRecs(moto_rec, ob52prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y25 -= ob_y_move;
                action = true;
            }
            Rectangle ob53prime_rec = ob53_rec; ob53prime_rec.width = 110; ob53prime_rec.height = 505;
            if(CheckCollisionRecs(moto_rec, ob53prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y27 -= ob_y_move;
                action = true;
            }
            Rectangle ob54prime_rec = ob54_rec; ob54prime_rec.width = 110; ob54prime_rec.height = 750;
            if(CheckCollisionRecs(moto_rec, ob54prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y39 -= ob_y_move;
                action = true;
            }
            Rectangle ob55prime_rec = ob55_rec; ob55prime_rec.width = 10; ob55prime_rec.height = 520;
            if(CheckCollisionRecs(moto_rec, ob55prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y43 -= ob_y_move;
                action = true;
            }
            Rectangle ob56prime_rec = ob56_rec; ob56prime_rec.width = 100; ob56prime_rec.height = 340;
            if(CheckCollisionRecs(moto_rec, ob56prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText("SORRY!!!", GetScreenWidth() / 2.9, GetScreenHeight() / 6 , 80, WHITE);
                DrawText("You loosed", GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y44 -= ob_y_move;
                action = true;
            }
            Rectangle ob57prime_rec = ob57_rec; ob57prime_rec.width = 8; ob57prime_rec.height = 318;
            if(CheckCollisionRecs(moto_rec, ob57prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y45 -= ob_y_move;
                action = true;
            }
            Rectangle ob58prime_rec = ob58_rec; ob58prime_rec.width = 10; ob58prime_rec.height = 490;
            if(CheckCollisionRecs(moto_rec, ob58prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                //DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y45 -= ob_y_move;
                action = true;
            }
            Rectangle ob59prime_rec = ob59_rec; ob59prime_rec.width = 80; ob59prime_rec.height = 740;
            if(CheckCollisionRecs(moto_rec, ob59prime_rec)){
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);

                DrawRectangleRec(page_End, DARKGRAY);
                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, GetScreenHeight() / 4 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                if(s < 10){
                    if(mn < 10){DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                    else {DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, GetScreenHeight() / 3, 50, WHITE);}
                }
                collision = true;
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() - 1050, GetScreenHeight() - 300, 60, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

                moto_speed = 0;
                moto_speedup = 0;
                moto_slowdown = 0;
                y46 -= ob_y_move;
                action = true;
            }

        }


    /**
        ************************************************FERMETURE DU JEU ****************************************************
        ***********************************************************************************************************************
    */

        if(moto_y <= -30100){
                raceOver = true;
                PauseMusicStream(songMoto);
                UpdateMusicStream(music);
                PlayMusicStream(music);
                DrawRectangle(0, -31000, GetScreenWidth(), GetScreenHeight()+80, ORANGE);
                DrawText("CONGRATULATIONS!!!", GetScreenWidth() / 7, -30750 , 80, WHITE);
                DrawText("You finished", GetScreenWidth() / 3, -30650 , 60, WHITE);

                DrawText(TextFormat("Score: %d", score), GetScreenWidth() / 3, -30500 , 60, WHITE);
                if(s >= 10){
                    if(mn >= 10){
                        DrawText(TextFormat("Time: 0%d : %d : %d", h, mn, s), GetScreenWidth() / 3.4, -30420, 50, WHITE);
                    }
                    else {
                        DrawText(TextFormat("Time: 0%d : 0%d : %d", h, mn, s), GetScreenWidth() / 3.4, -30420, 50, WHITE);
                    }
                }
                if(s < 10){
                    if(mn < 10){
                        DrawText(TextFormat("Time: 0%d : 0%d : 0%d", h, mn, s), GetScreenWidth() / 3.4, -30420, 50, WHITE);
                    }
                    else {
                        DrawText(TextFormat("Time: 0%d : %d : 0%d", h, mn, s), GetScreenWidth() / 3.4, -30420, 50, WHITE);
                    }
                }
                DrawText("PRESS ESCAPE TO EXIT", GetScreenWidth() / 3.5, -30100, 40, WHITE);
                if( IsKeyDown( KEY_ESCAPE) ) {
                    CloseWindow();
                }

            }



        EndMode2D();

        EndDrawing();


    }


    /******
        ******************************************LIBERATION DE L'ESPACE MEMOIRE DE TOUTES LES IMAGES DU JEU************************************
        ****************************************************************************************************************************************
    ****/

    UnloadImage(moto_image);
    UnloadTexture(moto_texture);

    UnloadImage(flag);
    UnloadImage(start_line);
    UnloadImage(end_line);

    UnloadImage(soil_image);
    UnloadTexture(soil_texture);

    /**Les obstacles**/
    UnloadImage(ob1);
    UnloadImage(ob2);
    UnloadImage(ob3);
    UnloadImage(ob4);
    UnloadImage(ob5);
    UnloadImage(ob6);
    UnloadImage(ob7);
    UnloadImage(ob8);
    UnloadImage(ob9);
    UnloadImage(ob10);
    UnloadImage(ob11);
    UnloadImage(ob12);
    UnloadImage(ob13);

    /**les pièces**/
    UnloadImage(p5);
    UnloadImage(p6);
    UnloadImage(p7);
    UnloadImage(p8);

    /**Les musiques**/
    UnloadMusicStream(music);
    UnloadMusicStream(countDown);
    UnloadMusicStream(songMoto);
    CloseAudioDevice();

    CloseWindow();

    return 0;
}

