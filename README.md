# Station Météo Arduino

## Description
Ce projet est une station météo basée sur Arduino qui permet de collecter et d'enregistrer différentes données environnementales. La station dispose de plusieurs modes de fonctionnement et peut mesurer :

- Température
- Humidité
- Pression atmosphérique
- Luminosité
- Position GPS

## Caractéristiques

### Modes de fonctionnement
- **Mode Standard** : Enregistrement normal des données
- **Mode Economy** : Enregistrement alterné des données GPS pour économiser l'énergie
- **Mode Maintenance** : Affichage des données en temps réel sur le port série
- **Mode Configuration** : Configuration des paramètres via le port série

### Composants matériels
- Arduino (compatible)
- Capteur BME280 (température, humidité, pression)
- Module GPS
- Capteur de luminosité
- Module RTC DS1307
- Lecteur de carte SD
- LEDs RGB chainables
- 2 boutons de contrôle

## Installation

1. Connectez les composants selon le schéma de câblage
2. Installez les bibliothèques requises :
   - TinyGPS++
   - Adafruit_BME280
   - RTClib
   - SD
   - ChainableLED
   - SoftwareSerial

## Configuration

Les paramètres configurables incluent :
- Intervalles d'enregistrement
- Seuils des capteurs
- Taille maximale des fichiers
- Timeout GPS
- Activation/désactivation des capteurs

## Utilisation

### Contrôles
- **Bouton 1** (maintenu) : Basculer entre mode Standard et Economy
- **Bouton 2** (maintenu) : Basculer vers/depuis le mode Maintenance
- **Bouton 2** au démarrage : Entrer en mode Configuration

### Indicateurs LED
- **Vert** : Mode Standard
- **Bleu** : Mode Economy
- **Orange** : Mode Maintenance
- **Jaune** : Mode Configuration
- **Rouge** : Erreur

### Format des données
Les données sont enregistrées sur la carte SD au format :
DD/MM/YYYY HH:MM:SS Lumière:XXX T:XX.XX °C H:XX.XX % P:XXXX.XX hPa Latitude:XX.XXXXXX Longitude:XX.XXXXXX

## Gestion des erreurs
- Surveillance des erreurs de capteurs
- Détection de carte SD pleine
- Validation des données GPS
- Rotation automatique des fichiers logs

## Maintenance
- Vérifiez régulièrement l'espace disponible sur la carte SD
- Calibrez les capteurs si nécessaire
- Mettez à jour l'heure RTC si nécessaire
