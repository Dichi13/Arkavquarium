public abstract class HewanAir extends AquariumObject {
  public static final double BASERADIUS = 10;
  private boolean hadapKanan;
  private double direction; //Arah gerak dalam radian
  private final double radius;

  public HewanAir() {
    this.setDirection(0);
    this.radius = BASERADIUS;
  }
  public HewanAir(final double paramDirection, final double paramRadius) {
    this.setDirection(paramDirection);
    this.radius = paramRadius;
  }

  //GettsetSetter
  public final double getDirection() {
    return this.direction;
  }
  public final void setDirection(final double paramDirection) {
    this.direction = paramDirection;
    this.hadapKanan = Math.cos(paramDirection) > 0;
  }
  public final double getRadius() {
    return this.radius;
  }
  public final boolean isHadapKanan() {
    return this.hadapKanan;
  }
}