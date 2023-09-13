from django.contrib import admin
from django.urls import path
from .views import *

urlpatterns = [
    path('', index, name ='index'),
    path('contact/', contact, name='contact'),
    path('createpizza/', create_pizza, name='createpizza'),
    path('createpizza/delivery/', delivery, name='delivery'),
    path('sumdetails/', sumdetails, name='sumdetails')
]