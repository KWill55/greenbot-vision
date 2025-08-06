Autonomous Microgreens Monitoring & Harvesting System

Overview of Directory Structure:

| Folder      | Type        | Role                                                                 |
| ----------- | ----------- | -------------------------------------------------------------------- |
| `data/`     | Shared      | Used by both backend and scripts                                     |
| `scripts/`  | Utility     | Data collection, processing, visualization (Python, Bash, etc.)      |
| `hardware/` | Hardware    | ESP32 firmware, GPIO control, I2C sensors, motor control, RTOS stuff |
| `models/`   | Backend-ish | ML model training/inference (can be called from backend)             |
| `frontend/` | Frontend    | Web/mobile dashboard (HTML/CSS/JS, Flutter, etc.)                    |
| `backend/`  | Backend     | APIs, logic, sensor data aggregation, maybe ML inference             |
| `config/`   | Shared      | System config used across hardware/backend/scripts                   |
----------------------------------------------------------------------------------------------------