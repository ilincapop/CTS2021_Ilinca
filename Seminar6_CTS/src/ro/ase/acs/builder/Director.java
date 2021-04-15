package ro.ase.acs.builder;

public class Director {
	
	private ProductBuilderV2 productBuilderV2=new ProductBuilderV2();
	
	public Director() {
		
	}
	public Product buildVeganChocolat(float price) {
		return productBuilderV2
		.addName("Chocolat")
		.addPrice(price)
		.addQuantity(5)
		.addisVeganFriendly(true)
		.build();
	}
	
	// ...
}
