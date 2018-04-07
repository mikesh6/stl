#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "Usager.h"
#include "GestionnaireProduits.h"
using namespace std;



class Client : public Usager
{
  public:
    Client(unsigned int codeClient = 0);
    Client(const string &nom, const string &prenom, int identifiant, const string &codePostal, unsigned int codeClient = 0);
	~Client();

    unsigned int obtenirCodeClient() const;
	void modifierCodeClient(unsigned int codeClient);
	
	GestionnaireProduits*  obtenirPanier() const;
    virtual double obtenirTotalAPayer() const;
    void afficherPanier() const;
    virtual void afficher() const;
	virtual void enleverProduit(Produit *produit);
	virtual void ajouterProduit(Produit *produit);
    virtual void reinitialiser();
	
	Produit* trouverProduitPlusCher() const;
  
  protected:
    GestionnaireProduits*  panier_;
	
  private:
    unsigned int codeClient_;
};

#endif
