/** Implementasi kelas Pellet.
 * @author AbnerA
 */
public class Pellet extends AquariumObject {
    /**
     * PELLETSPEED adalah konstanta kecepatan Pellet.
     */
    public static final int PELLETSPEED = 30;
    /**
     * HARGAPELLET adalah konstanta harga Pellet.
     */
    public static final int HARGAPELLET = 1;
    /**
     * Konstruktor Pellet, mengisi absis dan ordinat dari Pellet dengan
     * parameter. Speed Pellet diisi konstanta PELLETSPEED.
     * @param absis
     * @param ordinat
     */
    public Pellet(final double paramAbsis, final double paramOrdinat) {
        super(paramAbsis, paramOrdinat, PELLETSPEED);
    }
    /**
     * Method move mengubah nilai ordinat Pellet.
     * @param time
     */
    @Override
    public final void move(final double time) {
        this.setOrdinat(this.getOrdinat() + this.getSpeed() * time);
    }
}
