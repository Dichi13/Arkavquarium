void help_page();

bool main_menu(double cx, double cy) {
    bool running = true;
    int select = 0;
    while (running) {
        //draw_image("background.jpg", cx, cy);
        draw_text("OOPQuarium", 25, SCREEN_WIDTH/2, SCREEN_HEIGHT/4, 0xFF, 0xFF, 0xFF);
        switch (select) {
            case 0:
                draw_text("Start", 20, cx, cy, 0xFF, 0xFF, 0x00);
                draw_text("Help", 20, cx, cy+30, 0xFF, 0xFF, 0xFF);
                draw_text("Quit", 20, cx, cy+60, 0xFF, 0xFF, 0xFF);
                break;
            case 1:
                draw_text("Start", 20, cx, cy, 0xFF, 0xFF, 0xFF);
                draw_text("Help", 20, cx, cy+30, 0xFF, 0xFF, 0x00);
                draw_text("Quit", 20, cx, cy+60, 0xFF, 0xFF, 0xFF);
                break;
            case 2:
                draw_text("Start", 20, cx, cy, 0xFF, 0xFF, 0xFF);
                draw_text("Help", 20, cx, cy+30, 0xFF, 0xFF, 0xFF);
                draw_text("Quit", 20, cx, cy+60, 0xFF, 0xFF, 0x00);
                break;
        }
        handle_input();
        for (auto key : get_tapped_keys()) {
            switch (key) {
            // r untuk reset
            case SDLK_UP:
                select = (select + 2)% 3;
                break;
            // x untuk keluar
            case SDLK_DOWN:
                select = (select + 1)% 3;
                break;
            case SDLK_SPACE:
                if (select == 0) {return true;}
                else if (select == 1) { help_page();  } 
                else {return false;}
            }
        }

        update_screen();
    }
}

void help_page() {
    clear_screen();
    bool running = true;
    while(running) {
        //draw_image("background.jpg", 30, 30); 
        draw_text("Gunakan tombol panah untuk menggerakkan cursor", 20, 30, 30, 0xFF, 0xFF, 0xFF);
        draw_text("Gunakan tombol G untuk membeli Guppy baru", 20, 30, 60, 0xFF, 0xFF, 0xFF);
        draw_text("Gunakan tombol P untuk membeli Piranha baru", 20, 30, 90, 0xFF, 0xFF, 0xFF);
        draw_text("Gunakan tombol F untuk membeli Makanan Ikan", 20, 30, 120, 0xFF, 0xFF, 0xFF);
        draw_text("Gunakan tombol T untuk membeli Telur", 20, 30, 150, 0xFF, 0xFF, 0xFF);
        draw_text("Kumpulkan koin dan beli 3 Telur untuk memenangkan permainan!", 30, 30, 200, 0xFF, 0xFF, 0xFF);
        draw_text("Pencet tombol apapun untuk kembali", 15, 20, SCREEN_HEIGHT - 20, 0xFF, 0xFF, 0xFF);
        handle_input();
        for (auto key: get_tapped_keys()) {
            switch (key) {
                default: return;
            }
        }
        update_screen();
    }
}
