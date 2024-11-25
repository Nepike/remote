from django.contrib import admin
from django.urls import path, include
from .views import handle_command

urlpatterns = [
    path('<str:ip>/<str:command>/', handle_command, name='sender'),
]