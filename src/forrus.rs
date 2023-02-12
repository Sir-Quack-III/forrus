pub mod forrus {
    pub fn round(inp: u8, key: u8) -> u8 {
        let mut out = inp;

        out ^= key;
        out = out.rotate_left(3);
        out = (u128::pow(out.into(), 5) % 173) as u8;
        out ^= (u128::pow(key.into(), 5) % 173) as u8;

        out
    }

    pub fn hash(inp: &[u8; 16]) -> [u8; 16] {
        let hash_in = inp;
        let mut hash_out = [0u8; 16];

        for idx in 0..16 {
            let i = hash_in[idx];
            let mut c = round(i as u8, 2);
            for _ in 0..14 {
                c = round(c, 2);
                // println!("{}", c);
            }

            hash_out[idx] = round(hash_in[idx], c as u8);
        }

        hash_out
    }
}