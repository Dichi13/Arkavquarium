#include "oop.hpp"
#include "Aquarium.h"
#include "LinkedList.h"
#include "HewanAir.h"
#include "AquariumObject.h"
#include "Ikan.h"
#include "Guppy.h"
#include "Piranha.h"
#include "Koin.h"
#include "Pellet.h"
#include "Siput.h"
#include <iostream>
#include <math.h>
#include <sstream>

using namespace std;

const double speed = 100; // pixels per second
const int START_MONEY = 50;
const int HargaTelur = 200;


bool main_menu(double centerx, double centery) {
    bool running = true;
    int select = 0;
    while (running) {
        draw_image("background.jpg", centerx, centery);
        draw_text("OOPQuarium", 25, SCREEN_WIDTH/2, SCREEN_HEIGHT/4, 0xFF, 0xFF, 0xFF);
        switch (select) {
            case 0:
                draw_text("Start", 20, centerx, centery, 0xFF, 0xFF, 0x00);
                draw_text("Quit", 20, centerx, centery+30, 0xFF, 0xFF, 0xFF);
                break;
            case 1:
                draw_text("Start", 20, centerx, centery, 0xFF, 0xFF, 0xFF);
                draw_text("Quit", 20, centerx, centery+30, 0xFF, 0xFF, 0x00);
                break;
        }
        handle_input();
        for (auto key : get_tapped_keys()) {
            switch (key) {
            // r untuk reset
            case SDLK_UP:
                select = (select + 1)% 2;
                break;
            // x untuk keluar
            case SDLK_DOWN:
                select = (select + 1)% 2;
                break;
            case SDLK_SPACE:
                if (select == 0) {return true;}
                else {return false;}
            }
        }

        update_screen();
    }
}

int main( int argc, char* args[] )
{
    init();
    
    double cy = SCREEN_HEIGHT / 2;
    double cx = SCREEN_WIDTH / 2;
    bool running = main_menu(cx, cy);
    // Menghitung FPS
    int frames_passed = 0;
    double starttime = time_since_start();
    double fpc_start = time_since_start() - starttime;
    std::string fps_text = "FPS: 0";
    std::string waktu = "Tes";
    std::string strMoney;
    std::string strHargaGuppy;
    std::string strHargaPiranha;
    std::string strHargaTelur;
    std::string strJumlahTelur;
	
	// Inisialisasi semua Obyek
	// Aquarium
	Aquarium Aq(SCREEN_WIDTH, SCREEN_HEIGHT);
    // Posisi cursor

    // 1 Guppy
    Aq.addGuppy(new Guppy(0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));

    // Player Stats
    int EggCount = 0;
    int Money = START_MONEY;



    double prevtime = time_since_start()-starttime;
	
    while (running && (EggCount < 3 && (Money >= HargaGuppy || !Aq.getListGuppy().isEmpty() || !Aq.getListPiranha().isEmpty()))) {
        double now = time_since_start() - starttime;
        double sec_since_last = now - prevtime;
        prevtime = now;

        handle_input();
        if (quit_pressed()) {
            running = false;
        }

        // Gerakkan ikan selama tombol panah ditekan
        // Kecepatan dikalikan dengan perbedaan waktu supaya kecepatan ikan
        // konstan pada komputer yang berbeda.
        for (auto key : get_pressed_keys()) {
            switch (key) {
            case SDLK_UP:
                cy -= speed * sec_since_last;
                break;
            case SDLK_DOWN:
                cy += speed * sec_since_last;
                break;
            case SDLK_LEFT:
                cx -= speed * sec_since_last;
                break;
            case SDLK_RIGHT:
                cx += speed * sec_since_last;
                break;
            }
        }

        // Proses masukan yang bersifat "tombol"
        for (auto key : get_tapped_keys()) {
            switch (key) {
            // r untuk reset
            case SDLK_r:
                cy = SCREEN_HEIGHT / 2;
                cx = SCREEN_WIDTH / 2;
                break;
            // x untuk keluar
            case SDLK_x:
                running = false;
                break;
            // g untuk beli guppy
            case SDLK_g:
				if(Money >= HargaGuppy){
					Aq.addGuppy(new Guppy(0, rand()%SCREEN_WIDTH, rand()%SCREEN_HEIGHT));
					Money -= HargaGuppy;
				}
                break;
            // p untuk beli piranha
            case SDLK_p:
				if(Money >= HargaPiranha){
					Aq.addPiranha(new Piranha(rand()%SCREEN_WIDTH, rand()%SCREEN_HEIGHT));
					Money -= HargaPiranha;
				}
                break;
            // f untuk memunculkan pellet
            case SDLK_f:
				if(Money >= HargaPellet){
					Aq.addPellet(new Pellet(cx, 0));
					Money -= HargaPellet;
				}
                break;
            // t untuk beli telur
            case SDLK_t:
				if(Money >= HargaTelur){
					EggCount += 1;
					Money -= HargaTelur;
				}
            }
        }

        // Update FPS setiap detik
        frames_passed++;
        if (now - fpc_start > 1) {
            std::ostringstream strs;
            strs << "FPS: " ;
            strs << frames_passed/(now - fpc_start);
            fps_text = strs.str();;
            fpc_start = now;
            frames_passed = 0;
        }
        
        // Konversi waktu ke string
        std::ostringstream strs2;
        strs2 << now;
        waktu = strs2.str();
        
        // Konversi money ke string
        std::ostringstream strs3;
        strs3 << Money;
        strMoney = strs3.str(); 
        
        // Update status Aquarium
        Money += Aq.updateAquarium(sec_since_last);
		
        // Gambar Cursor di posisi yang tepat.
        clear_screen();
        // Gambar background
		draw_image("background.jpg", SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
		
        //draw_text(fps_text, 18, 10, 30, 0, 0, 0);
        draw_image("cursor2.png", cx, cy);
	
		
		AquariumObject* P;
		Guppy *G; 
        // Gambar semua Guppy
		for(int i = 0; i < Aq.getListGuppy().length(); i++){
			P = Aq.getListGuppy().get(i);
			G = (Guppy*) P;
			if(G->getLevel() == 1){
				if(G->isHadapKanan()){
					draw_image("Guppy1R.png", P->getX(), P->getY());
				}
				else{
					draw_image("Guppy1L.png", P->getX(), P->getY());
				}
			}
			else if(G->getLevel() == 2){
				if(G->isHadapKanan()){
					draw_image("Guppy2R.png", P->getX(), P->getY());
				}
				else{
					draw_image("Guppy2L.png", P->getX(), P->getY());
				}
			}
			else{
				if(G->isHadapKanan()){
					draw_image("Guppy3R.png", P->getX(), P->getY());
				}
				else{
					draw_image("Guppy3L.png", P->getX(), P->getY());
				}
			}
		}

        // Gambar semua Piranha
        Piranha *Pi;
		for(int i = 0; i < Aq.getListPiranha().length(); i++){
			P = Aq.getListPiranha().get(i);
			Pi = (Piranha*) P;
			if(Pi->isHadapKanan()){
				draw_image("PiranhaR.png", P->getX(), P->getY());
			}
			else{
				draw_image("PiranhaL.png", P->getX(), P->getY());
			}
		}

		// Gambar semua Koin
		for(int i = 0; i < Aq.getListKoin().length(); i++){
			P = Aq.getListKoin().get(i);
			draw_image("Koin.png", P->getX(), P->getY());
		}

		// Gambar semua Pellet
		for(int i = 0; i < Aq.getListPellet().length(); i++){
			P = Aq.getListPellet().get(i);
			draw_image("Pellet.png", P->getX(), P->getY());
		}

		// Gambar Siput
		P = Aq.getSiput();
		Siput *S = (Siput*) P;
		if(S->isHadapKanan()){
			draw_image("SiputR.png", P->getX(), P->getY());
		}
		else{
			draw_image("SiputL.png", P->getX(), P->getY());
		}
		
		// Tampilan UI
		draw_image("HargaGuppy.png", SCREEN_WIDTH-60, 160);
		draw_image("HargaPellet.png", SCREEN_WIDTH-60, 260);
		draw_image("HargaPiranha.png", SCREEN_WIDTH-60, 360);
		draw_image("PanelUang.png", 85, 35);
		draw_image("PanelWaktu.png", 85, 85);
		if (EggCount == 0) {
			draw_image("Telur1.png", SCREEN_WIDTH-60, 60);
		} else if (EggCount == 1) {
			draw_image("Telur2.png", SCREEN_WIDTH-60, 60);
		} else {
			draw_image("Telur3.png", SCREEN_WIDTH-60, 60);
		}
		draw_text(waktu, 18, 30, 70, 0, 0, 0);
        draw_text(strMoney, 18, 30, 20, 0, 0, 0);
		
        update_screen();
    }
	
	clear_screen();
	// Gambar background
	draw_image("background.jpg", SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
	if(EggCount >= 3){
		//Win message
		draw_text("You Win!!!", 36, 10, SCREEN_HEIGHT/2, 0, 0, 0);
	}
	else{
		//Lose message
		draw_text("Game Over", 36, 10, SCREEN_HEIGHT/2, 0, 0, 0);
	}
	update_screen();
	
	double prevendtime = time_since_start();
	double nowend = time_since_start();
	double sec_since_end = nowend - prevendtime;
	while(sec_since_end < 5){
		nowend = time_since_start();
		sec_since_end = nowend - prevendtime;
	}
    close();

    return 0;
}
