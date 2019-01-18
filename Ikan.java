import java.util.Random;

public abstract class Ikan extends HewanAir {
    public static final int RADIUS = 50;
    private boolean hungry;
    private double timer;
    private double timergerak;
    private static final int hungerThreshold = 10;
    private static final int deathThreshold = 20;

    public Ikan(double absis, double ordinat, double speed, double direction, double radius) {
        super(absis,ordinat,speed);
        timer = 0;
        timergerak = 0;
        hungry = false;
    }
    boolean isHungry() {
        return hungry;
    }
    double getTimer(){
        return timer;
    }
    void setHungry(){
        hungry = (timer > hungerThreshold);
    }
    void setTimer(double time){
        timer = time;
    }
  
    /* METHOD SPESIFIKASI */
    //bergerak secara acak
    void wander(int sizeAbsis, int sizeOrdinat){
        if (this.getAbsis() + Math.cos(direction)*speed*(5-timergerak) > sizeAbsis || this.getAbsis() + Math.cos(direction)*speed*(5-timergerak) < 0 ||
            this.getOrdinat() + Math.sin(direction)*speed*(5-timergerak) > sizeOrdinat || this.getOrdinat() + Math.sin(direction)*speed*(5-timergerak) < 0){
                Random direct = new Random();
                this.setDirection(this.getDirection()+direct.nextFloat()*2+2);
                if (this.getDirection() > 10) {this.setDirection(this.getDirection()-2*Math.PI);}
        } else {
            if (timergerak > 5){
                timergerak = 0;
                this.setDirection(Math.PI*Math.cos(timer));
            }
        }
    }
    
    //Menjatuhkan Koin
    abstract Koin coinDrop(int value);
    
    void move(double timePassed){
        double horizontalMove = Math.cos(direction)*speed*timepassed;
        double verticalMove = Math.sin(direction)*speed*timepassed;
        this.setOrdinat(this.getOrdinat()+verticalMove);
        this.setAbsis(this.getAbsis()+horizontalMove);
    }

    int pursue(List<AquariumObject> food){
        AquariumObject pursued;
        int iMin = 0;
        double minDist = this.distance(food.get(0));
        for(int i = 1; i < food.length(); i++){
            if (this.distance(food.get(i)) < minDist){
                iMin = i;
                minDist = this.distance(food.get(i));  
            }
        }
        pursued = food.get(iMin);
        setDirection(Math.atan2(pursued.getOrdinat() - this.getOrdinat(), pursued.getAbsis() - this.getAbsis()));
        return iMin;
    }
    
    abstract int consume(List<AquariumObject> food, int indeks);

    boolean updateIkan(int sizeAbsis, int sizeOrdinat, List<AquariumObject> food, List<AquariumObject> coins, double timePassed) {
        this.timer += timePassed;
        this.timergerak += timePassed;
        if (hungry && timer > deathTimerThreshold) {
            return false;
        } else if (!hungry && timer > hungerTimerThreshold) {
            hungry = true;
        }
        return true;
    }

}