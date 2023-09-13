from django.contrib import admin
from .models import *

admin.site.register(CustomerDetails)
admin.site.register(PizzaCheese)
admin.site.register(PizzaSauce)
admin.site.register(PizzaCrust)
admin.site.register(PizzaSize)
# Register your models here.

class PizzaAdmin(admin.ModelAdmin):
    list_display = ('pizza_sizes', 'pizza_crusts', 'pizza_sauces', 'pizza_cheeses', 'display_toppings')

    def display_toppings(self, obj):
        toppings = [topping.name for topping in obj.toppings.all()]
        if toppings:
            return ", ".join(toppings)
        else:
            return "None"

    display_toppings.short_description = 'Toppings'

admin.site.register(Pizza, PizzaAdmin)
admin.site.register(PizzaToppings)