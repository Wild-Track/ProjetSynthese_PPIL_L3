package formParser;

import form.Form;

public abstract class FormParserCOR extends FormParser {
	/**
	 * Classe parentes de tout les differents parseur
	 */
	protected FormParserCOR suivant;
	
	public FormParserCOR(FormParserCOR suivant) {
		super();
		this.suivant = suivant;
	}

	/**
	 * Teste si le parseur actuel est le bon sinon passe au suivant ou renvoie null si c'est le dernier
	 */
	@Override
	public Form findParser(String s) {
		Form f = Parser(s);
		if(f != null) {
			return f;
		}
		else {
			if(this.suivant != null) {
				return suivant.findParser(s);
			}
			else {
				return null;
			}
		}
	}

	public abstract Form Parser(String s);
	

	public FormParserCOR getSuivant() {
		return suivant;
	}

	public void setSuivant(FormParserCOR suivant) {
		this.suivant = suivant;
	}
}
