package ro.ase.acs.main;
import ro.ase.acs.builder.Director;
import ro.ase.acs.builder.Product;
import ro.ase.acs.builder.ProductBuilderV2;

public class Main {

	public static void main(String[] args) {

//		Product product = new Product("Milk", 5,500, null, 0, true, false );
//		Product product2=new Product("Chocolat", 7);
//		product2.setExpireDate(new Date());
//		//...
//		product2.setQuantity(10);
		
		Product product =new Product.ProductBuilder()
				.addName("Milk")
				.addPrice(5)
				.addisVeganFriendly(true)
				.build();
		
		ProductBuilderV2 productBuilderV2=new ProductBuilderV2();
		productBuilderV2.addName("Chocolat");
		productBuilderV2.addPrice(7);
		Product product4=productBuilderV2.build();
		
		System.out.println(product);
		System.out.println(product4);
		
		Director director=new Director();
		Product product5=director.buildVeganChocolat(10);
		System.out.println(product5);
	}

}
