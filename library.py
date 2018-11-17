# libarary.py

###### 1.
## 
# class Base:
# 	def foo(self):
# 		return 'foo'


###### 2. 
# how to make sure `bar` mehtod is implenmented in user code
# three commen methods:
##

## second method
class BaseMeta(type):
	def __new__(cls, name, bases, body):
		print('BaseMeta.__new__', cls, name, bases, body)
		if name is not 'Base': # skip base class
			if 'bar' not in body:
				raise TypeError("bad user class")
		return super().__new__(cls, name, bases, body)

class Base(metaclass=BaseMeta):
	def foo(self):
		return self.bar()


## first method
# old_bc = __build_class__
# def my_bc(fun, name , base=None, **kw):
# 	if base is Base:
# 		print('check if bar method defined')
# 	if base is not None:
# 		return old_bc(fun, name, base, **kw)
# 	return old_bc(fun, name, **kw)

# import builtins
# builtins.__build_class__ = my_bc

