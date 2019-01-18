public class Koin extends AquariumObject {
    public static final int COINSPEED = 30;
    private int value; // Nilai dari koin


    public Koin() {
	super(0, 0, COINSPEED);
	this.value = 0;
    }
    public Koin(final double absis, final double ordinat,
            final int paramValue) {
	super(absis, ordinat, COINSPEED);
	this.value = paramValue;
    }
		
    //Getter Setter
    public final int getValue() {
	return this.value;
    }
    public final void setValue(final int paramValue) {
    	this.value = paramValue;
    }
    
    @Override
    public final void move(final double time) {
	this.setOrdinat(this.getOrdinat() + this.getSpeed() * time);
    }
}
