Autonomous Microgreens Monitoring & Harvesting System


| Folder      | Type        | Role                                                                 |
| ----------- | ----------- | -------------------------------------------------------------------- |
| `frontend/` | Frontend    | Web/mobile dashboard (HTML/CSS/JS, Flutter, etc.)                    |
| `backend/`  | Backend     | APIs, logic, sensor data aggregation, maybe ML inference             |
| `hardware/` | Hardware    | ESP32 firmware, GPIO control, I2C sensors, motor control, RTOS stuff |
| `scripts/`  | Utility     | Data collection, processing, visualization (Python, Bash, etc.)      |
| `models/`   | Backend-ish | ML model training/inference (can be called from backend)             |
| `data/`     | Shared      | Used by both backend and scripts                                     |
| `config/`   | Shared      | System config used across hardware/backend/scripts                   |
