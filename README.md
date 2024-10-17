
# Worldwide Weather Watcher - Station Météo Embarquée

## Introduction

Le projet **Worldwide Weather Watcher** vise à développer un prototype de station météo embarquée destiné à équiper des navires pour la prévention de catastrophes naturelles. Cette station permettra de recueillir diverses données météorologiques via des capteurs, de les exploiter en temps réel et de les stocker sur une carte SD. Ces informations pourront être partagées entre navires pour améliorer la détection de phénomènes climatiques dangereux, tels que les cyclones.

## Matériel

La station météo repose sur une architecture matérielle simple et efficace, adaptée aux environnements marins. Le matériel utilisé inclut :

- **Microcontrôleur** : AVR ATmega328 (intégré à la carte Arduino)
- **Lecteur de carte SD (SPI)** : Stockage des données des capteurs
- **Horloge RTC (I2C)** : Gestion de la date et de l’heure
- **LED RGB (2-wire)** : Indicateur de statut du système
- **2 boutons poussoirs** : Interaction avec le système

### Capteurs :
- Pression atmosphérique (I2C ou SPI)
- Température de l’air (I2C ou SPI)
- Hygrométrie (I2C ou SPI)
- GPS (UART)
- Luminosité (analogique)

### Modules complémentaires à intégrer :
- Température de l’eau (analogique)
- Force du courant marin (I2C)
- Force du vent (I2C)
- Taux de particules fines (2-wire)

## Modes de Fonctionnement

Le système propose quatre modes de fonctionnement accessibles via les boutons poussoirs :

1. **Mode Standard** : Acquisition des données des capteurs à des intervalles réguliers (par défaut 10 minutes).
2. **Mode Configuration** : Permet de configurer le système via une interface série.
3. **Mode Maintenance** : Consultation des données des capteurs via le port série, avec possibilité de retirer la carte SD en toute sécurité.
4. **Mode Économique** : Réduit la consommation énergétique en ajustant la fréquence de collecte des données.

### Indicateurs de Statut (via LED RGB)
- Vert continu : Mode standard
- Jaune continu : Mode configuration
- Bleu continu : Mode économique
- Orange continu : Mode maintenance
- Rouge/bleu clignotant : Erreur horloge RTC
- Rouge/jaune clignotant : Erreur GPS
- Rouge/vert clignotant : Erreur capteur

## Livrables

### 1. Analyse du Système
Une analyse complète incluant des diagrammes UML/SysML, algorithmes, et schémas décrivant les fonctionnalités du projet.

### 2. Architecture du Programme
Présentation de l’architecture du programme avec les fonctions, variables et structures de données utilisées. Ce livrable n'est pas destiné à évoluer au fil du projet.

## Commandes de Configuration

Le système peut être configuré via une interface série. Voici quelques commandes disponibles :
- `LOG_INTERVAL=<valeur>` : Définit l'intervalle entre deux mesures (par défaut 10 minutes).
- `FILE_MAX_SIZE=<valeur>` : Taille maximale d’un fichier de log (par défaut 2Ko).
- `RESET` : Réinitialisation des paramètres par défaut.
- `VERSION` : Affiche la version du programme.

### Exemples de commandes pour les capteurs :
- `TEMP_AIR=1` : Active le capteur de température de l’air.
- `MIN_TEMP_AIR=-5` : Définit le seuil minimal pour le capteur de température.
- `HYGR=1` : Active le capteur d’hygrométrie.

## Conclusion

Le prototype de la station météo embarquée est une solution modulable et extensible, conçue pour fournir des informations précises en mer tout en optimisant la gestion énergétique. Ce projet permettra d’anticiper les catastrophes naturelles grâce à une collecte et un partage intelligent des données météorologiques.
