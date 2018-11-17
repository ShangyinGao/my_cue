# user.py
from library import Base

###### 1.
# user code used some function defined in libray, here `foo`
# to avoid crash before exectute this function, we can check if method exist using `hasattr`
## 
# assert hasattr(Base, 'foo'), "foo doesn't exist in base class"

# class Derived(Base):
# 	def bar(self):
# 		return self.foo()


###### 2. 
##
class Derived(Base):
	def bar(self):
		return 'bar'


