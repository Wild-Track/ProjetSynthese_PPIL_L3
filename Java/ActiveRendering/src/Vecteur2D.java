public class Vecteur2D
{
    public double x, y;

    public Vecteur2D(double x, double y)
    {
        super();
        this.x = x;
        this.y = y;
    }

    @Override
    public String toString()
    {
        return "(" + x + ", " + y + ")";
    }

    public Vecteur2D somme(Vecteur2D v)
    {
        return new Vecteur2D(this.x + v.x, this.y + v.y);
    }

    public Vecteur2D oppose()
    {
        return new Vecteur2D(-this.x, -this.y);
    }

    public Vecteur2D difference(Vecteur2D v)
    {
        return this.somme(v.oppose());
    }

    public Vecteur2D multiplication(double a)
    {
        return new Vecteur2D(a * this.x, a * this.y);
    }

    public Vecteur2D produitComplexe(Vecteur2D v)
    {
        return new Vecteur2D(this.x * v.x - this.y * v.y, this.x * v.y + this.y * v.x);
    }

    public static Vecteur2D polaire(double teta)
    {
        return new Vecteur2D(Math.cos(teta), Math.sin(teta));
    }

    public int[] arrondi()
    {
        return new int[] {(int) this.x, (int) this.y};
    }
}