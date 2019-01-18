


public class Aquarium {
	private int sizeAbsis, sizeOrdinat; // Ukuran akuarium
	private List<AquariumObject> ikanGuppy; // Linked list yang menyimpan objek bertipe Guppy
	private List<AquariumObject> ikanPiranha; // Linked list yang menyimpan objek bertipe Piranha
	private List<AquariumObject> koin; // Linked list yang menyimpan objek bertipe koin
	private List<AquariumObject> pellet; // Linked list yang menyimpan objek bertipe pellet
	private Siput snail;
		// Konstruktor
	public Aquarium() {
        sizeAbsis = 640;
        sizeOrdinat = 480;
        snail = new Siput(sizeAbsis/2, sizeOrdinat-20);
    }
	public Aquarium(int Absis, int Ordinat){
        sizeAbsis = Absis;
        sizeOrdinat = Ordinat;
        snail = new Siput(sizeAbsis/2, sizeOrdinat-20);
    }

		/* METHOD SPESIFIKASI */
		
        //Getter
        
        /**
         * 
         */
    public int getSizeAbsis() {
        return sizeAbsis;
    }
    public int getSizeOrdinat() {
        return sizeOrdinat;
    }
    public List<AquariumObject> getListGuppy(){
        return ikanGuppy;
    }
    public List<AquariumObject> getListPiranha(){
        return ikanPiranha;
    }
    public List<AquariumObject> getListKoin(){
        return koin;
    }
    public List<AquariumObject> getListPellet(){
        return pellet;
    }
    public Siput getSiput() {
        return snail;
    }
    
    // Memasukkan elemen hewan ke linked list bertipe HewanAir.
    void addGuppy(Guppy newGup) {
        ikanGuppy.add(newGup);
    }
    void addPiranha(Piranha newPir) {
        ikanPiranha.add(newPir);
    }
    // Memasukkan elemen koin/pelet ke linked list bertipe FallingObject.
    void addKoin(Koin newKoin) {
        koin.add(newKoin);
    }
    void addPellet(Pellet newPel){
        pellet.add(newPel);
    }
    
    int updateAquarium(double timePassed) {
        int len = ikan_guppy.length();
        for(int i = 0; i < len; i++) {
            if (!((Guppy)ikan_guppy.get(i)).updateIkan(sizeAbsis, sizeOrdinat, pellet, koin, timePassed)) {
                ikan_guppy.removeAt(i);
                i--;
                len = ikan_guppy.length();
            }
        }
            
        //Update Piranha
        len = ikan_piranha.length();
        for(int i = 0; i < len; i++) {
            Piranha tempP = (Piranha) ikan_piranha.get(i);
            bool alive = tempP.updateIkan(sizeAbsis, sizeOrdinat, ikan_guppy, koin, timePassed);
            if (!alive) {
            ikan_piranha.remove(ikan_piranha.get(i));
            i--;
            len = ikan_piranha.length();
            }
        }

            //Update Koin
        len = koin.length();
        for(int i = 0; i < len; i++) {
            Koin tempK = (Koin) koin.get(i);
            if (tempK.getY() < sizeOrdinat) { 
            tempK.move(timePassed);
            }
        }

            //Update Pellet
        len = pellet.length();
        for(int i = 0; i < len; i++) {
            Pellet tempP = (Pellet) pellet.get(i);
            if (tempP.getY() < sizeOrdinat) {
            tempP.move(timePassed);
            } else {
            pellet.remove(pellet.get(i));
            len = pellet.length();
            i--;
            }
        }

            //Update Siput;
        int moneyget = Snail.updateSiput(koin, timePassed);
        return moneyget;
    }
}