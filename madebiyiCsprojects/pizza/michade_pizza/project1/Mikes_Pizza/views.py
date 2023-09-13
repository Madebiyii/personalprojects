from django.http import HttpResponse
from django.shortcuts import render, redirect
from django.shortcuts import  get_object_or_404
from .forms import DeliveryForm
from .models import *
from .forms import *


def index(request):
    return render(request, 'index.html')

def contact(request):
  return render(request, 'contact.html')

def create_pizza(request):
    if request.method == "POST":
			
        form = PizzaForm(request.POST)
        if form.is_valid():
            pizz = form.save(commit=False)
            pizz.save()
            form.save_m2m()
            return render(request, 'pizzadone.html', {'pizz':pizz})
        else:

            return render(request, 'createpizza.html', {'form': form})
    else:
        
        form = PizzaForm()
        return render(request, 'createpizza.html', {'form': form})

def delivery(request):
    all_pizzas = Pizza.objects.latest('id')
    if request.method == "POST":

        form = DeliveryForm(request.POST)
        if form.is_valid():
            pizz = form.save()
            return redirect('sumdetails')
        else:

            return render(request, 'delivery.html', {'form': form})
    else:
        
        form = DeliveryForm()
        return render(request, 'delivery.html', {'form': form})

def sumdetails(request):
   
    order = Pizza.objects.latest('id')
    toppings = order.pizza_toppings.all()
    print(toppings)
    return render(request, 'sumdetails.html', {'order': order, 'toppings':toppings})