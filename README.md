# 1. Как поднять сайт у себя?
## 1.1. Зависимости
- Python 3.11+
## 1.2 Windows 10
```powershell
# Клонирование репозитория
git clone https://github.com/Nepike/remote

# Создание и активация виртуального окружения Python
python -m venv virtualenv
.\virtualenv\Scripts\activate

# Переход в папку с проектом
cd remote

# Установка нужных пакетов Python
pip install -r requirements.txt

# Миграции
python .\manage.py makemigrations
python .\manage.py migrate

# Запуск сервера:
python .\manage.py runserver
