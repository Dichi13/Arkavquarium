/**
 * Kelas AquariumObject.
 * @author AbnerA
 */
public abstract class AquariumObject {
    /**
     * Koordinat Aquarium di (absis,ordinat).
     */
    private double absis, ordinat;
    /**
     * Kecepatan AquariumObject.
     */
    private double speed;

    /**
     * Konstruktor Dasar.
     */
    public AquariumObject() {
        this.absis = 0;
        this.ordinat = 0;
        this.speed = 0;
    }
    /**
     * Konstruktor dengan parameter.
     * @param paramAbsis absis
     * @param paramOrdinat ordinat
     * @param paramSpeed speed
     */
    public AquariumObject(final double paramAbsis, final double paramOrdinat,
            final double paramSpeed) {
        this.absis = paramAbsis;
        this.ordinat = paramOrdinat;
        this.speed = paramSpeed;
    }
    // Getter dan setter
    /**
     * Getter Absis.
     * @return nilai absis
     */
    public final double getAbsis() {
        return this.absis;
    }
    /**
     * Getter Ordinat.
     * @return nilai ordinat
     */
    public final double getOrdinat() {
        return this.ordinat;
    }
    public final double getSpeed() {
        return this.speed;
    }
    public final void setAbsis(final double paramAbsis) {
        this.absis = paramAbsis;
    }
    public final void setOrdinat(final double paramOrdinat) {
        this.ordinat = paramOrdinat;
    }
    public final void setSpeed(final double paramSpeed) {
        this.speed = paramSpeed;
    }

    //Jarak ke object lain
    public final double distance(final AquariumObject obj) {
        return (Math.sqrt(Math.abs(Math.pow((double) (
                this.getAbsis() - obj.getAbsis()),
                (double) 2)
                + Math.pow((double) (
                        this.getOrdinat() - obj.getOrdinat()), (double) 2))));
    }

    //Fungsi untuk menggerakkan objek
    public abstract void move(double time);
}
