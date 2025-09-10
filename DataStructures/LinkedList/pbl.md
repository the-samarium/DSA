# Smart Fleet & Inventory Tracking System

## 1. On Each Truck

**Microcontroller:**  
- ESP32 or Raspberry Pi Zero W

**Modules/Sensors:**  
- GPS module: `NEO-6M` → real-time location tracking  
- RFID reader → scan goods in/out  
- Environmental sensors: `DHT22` (temperature & humidity, optional)

**Communication:**  
- LTE/4G module (`SIM800`/`SIM808` or `SIM7600`)  
- Wi-Fi (if coverage available)

**Software (Truck-side):**  
- Reads all sensor and RFID data  
- Publishes data to central Node.js server via **MQTT** or **REST API**

---

## 2. Central Node.js Server (Cloud or Local)

**Responsibilities:**  
- Receives incoming data from all trucks  
- Stores data in:  
  - **MongoDB** → inventory, truck IDs, timestamps  
  - **InfluxDB** *(optional)* → time-series sensor readings  
- Processes:
  - GPS → convert to coordinates for map display  
  - RFID → update inventory status  
  - Sensors → check for alerts (e.g., temperature threshold breach)  
- Exposes **API endpoints** for frontend

---

## 3. React Frontend

**Features:**  
- **Live Map** → Truck locations using Leaflet.js, Mapbox, or Google Maps API  
- **Inventory Table** → goods per truck & warehouse status  
- **Alerts** → notifications for delays or environmental breaches  
- **Graphs** → temperature & humidity trends over time

---

## 4. Data Flow Overview

```mermaid
flowchart TD
    A[Truck: ESP32 / Raspberry Pi Zero W] --> B[Communication Module: LTE/4G or Wi-Fi]
    B --> C[Node.js Central Server]
    C --> D[Database: MongoDB / InfluxDB]
    D --> E[React.js Dashboard]

    subgraph A1[Truck Components]
        A1a[GPS: NEO-6M]
        A1b[RFID Reader]
        A1c[Temp/Humidity Sensor: DHT22]
    end

    A1a --> A
    A1b --> A
    A1c --> A
