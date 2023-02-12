// mod torrus;
include!("./forrus.rs");

fn main() {
    let i = 'h' as u8;
    let k: [u8; 16] = [2, 90, 126, 43, 183, 111, 40, 193, 205, 23, 153, 64, 93, 42, 82, 69];

    let out = forrus::hash(&k);
    // println!("in: {:?}\nout: {:?}", k, out);
}
