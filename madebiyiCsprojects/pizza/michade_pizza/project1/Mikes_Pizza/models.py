from django.db import models


# Create your models here.
class PizzaSize(models.Model):

   id = models.AutoField(primary_key=True)
   pizza_sizes = models.CharField(max_length=20, default='Small')

   def __str__(self):
      return "{}".format(self.pizza_sizes)


class PizzaCrust(models.Model):
   PIZZA_CRUSTS = (
      ('Normal', 'Normal'),
      ('Thin', 'Thin'),
      ('Thick', 'Thick'),
      ('Gluten Free', 'Gluten Free')
   )
   id = models.AutoField(primary_key=True)
   pizza_crusts = models.CharField(max_length=20, choices=PIZZA_CRUSTS, default='Normal')

   def __str__(self):
      return "{}".format(self.pizza_crusts)


class PizzaSauce(models.Model):

   id = models.AutoField(primary_key=True)
   pizza_sauces = models.CharField(max_length=20, default='Tomato')

   def __str__(self):
      return "{}".format(self.pizza_sauces)


class PizzaCheese(models.Model):

   id = models.AutoField(primary_key=True)
   pizza_cheeses = models.CharField(max_length=20, default='Mozzarella')

   def __str__(self):
      return "{}".format(self.pizza_cheeses)

class PizzaToppings(models.Model):

   id = models.AutoField(primary_key=True)
   name = models.CharField(max_length=30, default='Pepperoni')

   def __str__(self):
      return "{}".format(self.name)

class Pizza(models.Model):
   id = models.AutoField(primary_key=True)
   pizza_sizes = models.ForeignKey(PizzaSize, on_delete=models.CASCADE)
   pizza_crusts = models.ForeignKey(PizzaCrust, on_delete=models.CASCADE)
   pizza_sauces = models.ForeignKey(PizzaSauce, on_delete=models.CASCADE)
   pizza_cheeses = models.ForeignKey(PizzaCheese, on_delete=models.CASCADE)
   pizza_toppings = models.ManyToManyField(PizzaToppings, blank=True, related_name='topping')

   def __str__(self):
      return "{} pizza with {} crust, {} based sauce, {} cheese and your toppings are... ".format(self.pizza_sizes, self.pizza_crusts, self.pizza_sauces, self.pizza_cheeses)

class CustomerDetails(models.Model):
   id = models.AutoField(primary_key=True)
   name = models.CharField(max_length=30)
   address = models.TextField()
   card_number = models.CharField(max_length=16, default='1234123412341234')
   expiry_date = models.CharField(max_length=5)
   cvv = models.CharField(max_length=3)