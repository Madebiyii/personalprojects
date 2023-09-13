from django import forms
from django.forms import ModelForm, ModelMultipleChoiceField, CheckboxSelectMultiple, ModelChoiceField
from django.core.exceptions import ValidationError
import re
from .models import *

class PizzaForm(ModelForm):
    pizza_toppings = ModelMultipleChoiceField(queryset=PizzaToppings.objects.all(), widget=CheckboxSelectMultiple)

    class Meta:
        model = Pizza
        fields = ['pizza_sizes', 'pizza_crusts', 'pizza_sauces', 'pizza_cheeses', 'pizza_toppings']

    def clean(self):
       
        cleaned_data = super().clean()
        pizza_sizes = cleaned_data.get("pizza_sizes")
        pizza_crusts = cleaned_data.get("pizza_crusts")
        pizza_sauces = cleaned_data.get("pizza_sauces")
        pizza_cheeses = cleaned_data.get("pizza_cheeses")
        pizza_toppings = cleaned_data.get("pizza_toppings")
    

class DeliveryForm(ModelForm):
    class Meta:
        model = CustomerDetails
        fields = ['name', 'address', 'card_number', 'expiry_date', 'cvv']

    def clean(self):


        card_number = self.cleaned_data.get("card_number")
        expiry_date = self.cleaned_data.get("expiry_date")
        cvv = self.cleaned_data.get("cvv")
       
        if len(card_number) < 16:
            raise ValidationError(
                {'card_number': "Card number should have at least 16 digits"})

        if not card_number.isdigit():
            raise ValidationError(
                {'card_number': "Enter 16 digits Number"})

        if not expiry_date[2] == "/":
            raise ValidationError(
                {'expiry_date': "Enter MM/YY"})

        month, year = expiry_date.split("/")
        if month.isdigit() and year.isdigit():
            if int(month) > 12 or int(month) < 1:
                raise forms.ValidationError({"expiry_date":"Invalid Month"})
            if int(year) < 23:
                raise forms.ValidationError({"expiry_date":"Invalid Year"})
        else:
            raise forms.ValidationError({"expiry_date":"Invalid Card Details"})


        if not cvv.isdigit():
            raise ValidationError(
                {'cvv': "Enter the last 3 digit at the back of your card"})

    def save(self, *args, **kwargs):
        self.full_clean()
        return super().save(*args, **kwargs)
