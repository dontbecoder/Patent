def judgement(input):
	if(input):
		return True
	else:
		return False	

class Invention(object):
	"""docstring for Invention"""
	def __init__(self, arg):
		# Input:	产品|方法|改进
		# Output:	新的技术方案
		super(Invention, self).__init__()
		self.arg = arg
	
	Patent_term=20		# year

class Utility(object):
	"""docstring for Utility"""
	def __init__(self, arg):
		# Input:	产品的形状|构造|形状+构造
		# Output:	适于实用的新的技术方案
		super(Utility, self).__init__()
		self.arg = arg
	Patent_term = 10 	# year						


class Design(object):
	"""docstring for Design"""
	def __init__(self, arg):
		# Input:	产品的形状|图案|形状+图案|色彩+形状|色彩+图案
		# Output:	富有美感 + 适于工业应用 的新设计
		super(Design, self).__init__()
		self.arg = arg
	Patent_term = 10	# year			


def Review():  # 复审
	print("This is Review stage!")	
	result = 1
	if():
		pass
	elif ():
		pass
	elif ():
		pass	

	return result		

def Invalid():	# 无效
	print("This is Invalid stage!")
	return True

def Oral_reveiw():	# 口审
	print("This is Oral review stage!")	

def Infringement():	# 侵权
	print("This is in CHECK Infringement stage")	

def Judical_Protection(has_guarantee): # 司法保护
	print("This is in Judical Protection stage")
	if(has_guarantee):
		if(judgement(1)):
			# Do it in 48 hours ,or + 48 hours			
			return True		
		else:
			return False	
	else:
		return False				

def Transfer():	# （专利申请权/专利权）转让转移
	pass


def Fake():	# 假冒
	pass


def Legal_relief():	# 其他专利纠纷的法律救济
	if("专利权已被授予"):
		# 专利申请权、专利权归属纠纷
		# 发明人、设计人资格纠纷
		# 职务发明创造的发明人、设计人的奖励和报酬纠纷
		# 在发明专利申请公布后、专利权授予前使用发明而未支付适当费用的纠纷

	# 其他专利纠纷
	pass









if(Judical_Protection(1)):
	# Sue in 15 days
	pass
else:
	# Cancel Judical_Protection
	pass	


if(Fake()):
	# 责令改正并公告
	# 没收违法所得 & 四倍以下罚款
	# 没有违法所得的，二十万以下罚款
	# 构成犯罪，追究刑事责任
	pass


# IPC (Internetional Patent Class) 国际专利分类表
# 五级分类：部 ，大类 ，小类 ，主组 ， 分组
# A部：人类生活必需（农，轻，医）
# B部: 作业、运输
# C部：化学、冶金
# D部：纺织、造纸 
# E部：固定建筑物（建筑，采矿）
# F部：机械工程
# G部： 物理
# H部： 电学
# 文献种类代码
# A 发明专利申请公布书
# B 发明专利说明书
# C 发明专利权部分无效宣告的公告
# U 实用新型专利说明书
# Y 实用新型专利权部分无效宣告的公告
# S 外观设计专利授权公告

#  授予专利权的条件
# 	新颖性 				
#		1.不属于现有技术
#		2.没有任何单位或者个人就同样的发明或者实用新型在申请日以前向国务院专利行政部门提出过申请，并记载在申请日以后公布的专利申请文件或者
#		公告的专利文件中。
#	创造性
#		1.与现有技术相比，具有突出的实质性特点
#		2.与现有技术相比，具有显著的进步
#	实用性
#		能够制造 | 使用 & 产生积极效果
#	（现有技术：申请日以前在国内外为公众所知的技术）
def Whether_to_grant_Patent():
	if(judgement()):		
		return True
	else:
		return False	