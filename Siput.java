public class Siput extends HewanAir implements Eater {
	public static final double SNAILRADIUS = 30;
	public static final double SNAILSPEED = 30;

	public Siput(float x, float y) {
		super(x, y, SNAILSPEED);
	}

	public void move(double timePassed) {
		if (this.hadap_kanan) {
			this.setAbsis(this.getAbsis() + speed * timePassed);
		} else {
			this.setAbsis(this.getAbsis() - speed * timePassed);
		}
	}

	public int consume(List<AquariumObject> coin, int indeks) {
		Koin caught = coin.get(indeks);
		int coinvalue = caught.getValue();
		coin.remove(coin.get(indeks));

		return coinvalue;
	}

	public int pursue(List<AquariumObject> coin) {
		AquariumObject p;
		int imin = 0;
		boolean ground;
		double minDist;

		minDist = this.distance(coin.get(0));
		ground = (coin.get(0).getOrdinat() >= this.getOrdinat());
		
		for (int i = 1; i < coin.length(); i++) {
			if (this.distance(coin.get(i)) < minDist) {
				if (ground) {
					if (coin.get(i).getOrdinat() >= this.getOrdinat()) {
						imin = i;
						minDist = this.distance(coin.get(i));
					}
				} else {
					imin = i;
					minDist = this.distance(coin.get(i));
				}
			}
		}

		p = coin.get(imin);
		if (p.getAbsis() < this.getAbsis()) {
			this.hadap_kanan = false;
		} else {
			this.hadap_kanan = true;
		}

		if (minDist < this.getRadius()) {
			return consume(coin, imin);
		} else {
			return 0;
		}
	}

	public int updateSiput(List<AquariumObject> coin, double timePassed) {
		if (!coin.isEmpty()) {
			int moneyget;

			moneyget = pursue(coin);
			move(timePassed);
			return moneyget;
		} else {
			return 0;
		}
	}
}