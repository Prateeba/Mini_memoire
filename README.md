## Mini_memoire
Ce travail propose un générateur d'automate transducteur satisfaisant certaines propriétés. Le générateur 
prend en entrée le nombre d'états, la densité, le nombre d'états initiaux et finaux, ainsi que les différentes propriétés à 
satisfaire et génère un transducteur satisfaisant ces propriétés.

## Utilisation 
cd vcsn-2.6/ <br />
cd Generateur/<br />
Le dossier generateurNotStop/ contient les générateurs qui ne s'arrêtent 
que lorsqu'ils ont généré un transducteur respectant les différents et ayant
autant d'états utiles que passé en paramètres.

Le dossier generateurstop/ contient le générateur qui s'arrête après avoir 
généré un transducteur respectant les différentes propriétés.

## Compilation
vcsn compile nomDuFichier.cpp <br />
./nomDuFichier nbEtatsTotaux Densité nbEtatsFinaux nbEtatsFinaux > nomDuFichierPourSauvegarderLeResultat.dot <br />
